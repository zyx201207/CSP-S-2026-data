#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define ll long long
mt19937_64 rd(time(0));

ll rand(ll l, ll r) {
	return rd() % (r - l + 1) + l;
}

void gen() {
	ofstream fout("migrate.in");
	fout << "0 1\n";
	int n = 10, d = rand(10, 100);
	fout << n << ' ' << d << '\n';
	vector <int> ve(n);
	for (int i = 0; i < n; i++) {
		ve[i] = rand(-50, 50);
	}
	sort(ve.begin(), ve.end());
	for (auto i : ve) fout << i << ' ';
	fout << '\n';
}

int main() {
	string s = "migrate";
	do {
		gen();
		system((s + ".exe").c_str());
		system("bf.exe");
//		cout << "used " << (clock() - st)*1./CLOCKS_PER_SEC << " s\n\n\n";
	} while(!system(("fc " + s + ".ans " + s + ".out").c_str()));
	system("pause");
} 

/*

0 1
10 21
-29 -18 -13 -3 2 20 30 34 35 44 


0 1
10 29
-44 -43 -37 -18 -9 -7 -1 10 25 47 

*/
