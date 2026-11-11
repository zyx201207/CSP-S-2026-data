#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

ifstream fin("card.in");
ofstream fout("card.out");

int find(vector<int> v, int value) {
	for (int i = 0;i < v.size();i++) {
		if (v[i] == value) return i;
	}
	return -1;
}

int main() {
	int m;
	fin >> m;
	const int n = m;
	fin >> m;
	const int _ = m;
	int a[n], b[_];
	memset(b, 0, sizeof b);
	for (int i = 0;i < n;i++) {
		fin >> a[i];
	}
	vector<int> v, cantuse;
	for (int i = 0;i < n;i++) {
		v.clear();
		cantuse.clear();
		for (int j = i;j < n;j++) {
			if (find(cantuse, a[j]) != -1) continue;
			while (find(v, a[j]) != -1) {
				cantuse.push_back(v[v.size() - 1]);
				v.pop_back();
			}
			v.push_back(a[j]);
		}
		for (int j = 0;j < m;j++) {
			if (find(v, j + 1) != -1) b[j]++;
		}
	}
	for (int i = 0;i < m;i++) {
		fout << b[i] << ' ';
	}
	fin.close();
	fout.close();
	return 0;
}
