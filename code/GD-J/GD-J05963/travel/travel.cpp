#include <fstream>
using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

int main() {
	int i1, i2, i3, i4;
	char c1, c2;
	fin >> i1 >> i2 >> c1 >> i3 >> i4 >> c2;
	fout << (int)(i1 == i3) << (int)(i1 == i3 && i2 == i4);
	if (c1 == 'A' || c1 == 'B' || c1 == 'C') {
		fout << (int)(c2 == 'A' || c2 == 'B' || c2 == 'C');
	} else {
		fout << (int)(c2 == 'D' || c2 == 'F');
	}
	if (c1 == 'A' || c1 == 'C') {
		fout << (int)(c2 == 'B');
	} else if (c1 == 'B') {
		fout << (int)(c2 == 'A' || c2 == 'C');
	} else if (c1 == 'D') {
		fout << (int)(c2 == 'F');
	} else {
		fout << (int)(c2 == 'D');
	}
	fin.close();
	fout.close();
	return 0;
}
