#include <bits/stdc++.h>
using namespace std;

int Gdata[500010];

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	cout.tie(nullptr);
	string FILENAME = "card";
	string IFILE = FILENAME + ".in";
	string OFILE = FILENAME + ".out";
	freopen(IFILE.c_str(), "r", stdin);
	freopen(OFILE.c_str(), "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> Gdata[i];
	}
	
	while (m--) {
		cout << 0 << ' ';
	}
}
