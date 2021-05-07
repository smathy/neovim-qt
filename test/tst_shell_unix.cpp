#include "tst_shell.h"

#include <QStringList>
#include <QTest>

namespace NeovimQt {

QStringList BinaryAndArgumentsNoForkWithCommand(const QString& command) noexcept
{
	return { NVIM_QT_BINARY, "--nofork", "--",  "-c", command };
}

void AddPlatformSpecificExitCodeCases() noexcept
{
	// On UNIX-like operating systems, the child exit code is represented as a
	// 8-bit integer. Therefore 256 overflows and becomes 0.
	// Reference: man for wait(2).
	QTest::newRow("Exit Code Overflow: 256cq")
		<< 256 << 0 << QByteArray("256cq");
}

} // namespace NeovimQt
