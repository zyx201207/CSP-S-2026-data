#include <fstream>
using namespace std;

ifstream fin("and.in");
ofstream fout("and.out");

int main() {
	int m;
	fin >> m;
	const int n = m;
	fin >> m;
	long long a[n];
	for (int i = 0;i < n;i++) {
		fin >> a[i];
	}
	long long o = a[0];
	for (int i = 1;i < n;i++) {
		o &= a[i];
	}
	fout << o;
	fin.close();
	fout.close();
	return 0;
}
