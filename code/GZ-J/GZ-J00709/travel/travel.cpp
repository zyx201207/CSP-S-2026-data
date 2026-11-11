// GZ-J00709 遵义市第十六中学 袁昊辰
#include <fstream>
#include <cmath>

#define filename "travel"

unsigned c1, s1, c2, s2;

unsigned letterIndexConvert(char letter)
{
	switch(letter)
		{
			case 'A':
				return 0;
			case 'B':
				return 1;
			case 'C':
				return 2;
			case 'D':
				return 4; // 过道占一列
			case 'F':
				return 5;
			default:
				return (uint8_t)-1;
		}
}

int main()
{
	std::ifstream inFile;
	std::ofstream outFile;
	inFile.open(filename ".in");
	outFile.open(filename ".out");

	char tmp1, tmp2;
	inFile >> c1 >> s1 >> tmp1;
	inFile >> c2 >> s2 >> tmp2;

	s1 = s1*10 + letterIndexConvert(tmp1);
	s2 = s2*10 + letterIndexConvert(tmp2);

	inFile.close();

	outFile << (c1 == c2)
	        << ((c1 == c2) and (s1/10 == s2/10))
	        << ((c1 == c2) and (s1/10 == s2/10) and (
	            (s1 % 10 < 3 and s2 % 10 < 3) or (s1 % 10 > 3 and s2 % 10 > 3)))
	        << ((c1 == c2) and abs(s1-s2) == 1);

	outFile.close();

	return 0;
}
