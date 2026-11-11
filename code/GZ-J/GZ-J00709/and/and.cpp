// GZ-J00709 遵义市第十六中学 袁昊辰
#include <fstream>

#define filename "and"

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open(filename ".in");
	outFile.open(filename ".out");
	
	inFile.close();
	outFile.close();
	
	return 0;
}

