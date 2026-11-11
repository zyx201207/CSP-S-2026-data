#include <fstream>
#include <string>
using namespace std;

ifstream fin("string.in");
ofstream fout("string.out");

int main() {
	string s;
	int n;
	fin >> n;
	for (int i = 0;i < n;i++) {
		char c;
		long long m;
		fin >> m >> c;
		s += string(m, c);
	}
	long long count = 0;
	for (long long i = 0;i < s.length() / 2;i++) {
		if (s[i] != s[s.length() - i - 1]) count++;
	}
	fout << count;
	fin.close();
	fout.close();
	return 0;
}
