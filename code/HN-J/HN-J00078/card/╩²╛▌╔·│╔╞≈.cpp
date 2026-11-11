/*
这是数据生成器 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("cardp.in", "w", stdout);
	srand(time(0));
	int n = 1000, m = 500;
	cout << n << ' ' << m << '\n';
	for(int i = 1; i <= n; i++) {
		int tmp = rand() % m;
		cout << (tmp + m) % m << ' ';
	} 
} 
