#include <bits/stdc++.h>
using namespace std;

// ._________________.
// |                 |
// |   <!> Warning   | 
// |     68分代码    |
// |_________________| 

int n; //(200000)
vector <int> a;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	/// 程序输入 & 初始化 
	cin >> n;
	//// 特判
	if (n == 1) {
		cout << 0;
		return 0;
	}
	/// 程序输入 & 初始化(Continued) 
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		string tc;
		cin >> tc;
		for (int j = 0; j < a[i]; ++j) {
			s += tc;
		}
	}
	//cerr << s << ' ' << s.size();
	int sl = s.size();
	bool isso = !(sl % 2);
	
	/// 暴力(?)
	unsigned long long cnt = 0;
	for (int i = 0; i < (isso ? (sl / 2) : (sl / 2 + 1) ); ++i) {
		if (!isso && (i == (sl / 2 + 1) ) ) continue;
		if (s[i] != s[sl - i - 1]) cnt++;
	}
	
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

