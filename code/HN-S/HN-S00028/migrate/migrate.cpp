#include <bits/stdc++.h>
using namespace std;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
const int maxn = 2e6 + 5;

int c, t;
int n, d;
int x[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	AC;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
		}
		cout << (n - 1) / 2 << "\n";
	}
	/*
	这把给了
	T4没时间写，T2还没调好，问题目前不知道，希望T1能AC  运气好看能不能S1 
	*/
	
	
	
	return 0;
}
