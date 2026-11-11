#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


int main() {
	string s = "subway";
	for (int i = 1; i <= 7; i++) {
		string s1 = s + char(i + '0');
		system(("copy " + s1 + ".in " + s + ".in").c_str());
		int st = clock();
		system((s + ".exe").c_str());
		cout << (clock() - st)*1./CLOCKS_PER_SEC << '\n';
		system(("fc " + s1 + ".ans " + s + ".out").c_str());
	}
	system("pause");
} 
