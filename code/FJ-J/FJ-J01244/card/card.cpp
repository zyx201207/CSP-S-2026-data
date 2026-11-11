#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
const int N = 1000010;
const int inf = 1e18;
using namespace std;
bool vis[N];
int a[N], last[N], ans[N];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	For(i, 1, n) cin >> a[i];
	vector<int> stk;
	For(l, 1, n) {
		memset(vis, 0, sizeof(vis));
		memset(last, 0, sizeof(last));
		For(i, l, n) {
			if(vis[a[i]]) {
				while(stk.size() && stk.back() > last[a[i]]) vis[a[stk.back()]] = 0, stk.pop_back();
			} else stk.push_back(i);
			last[a[i]] = i;
			vis[a[i]] = 1;
		}
		while(stk.size()) ans[a[stk.back()]] ++, stk.pop_back();
	}
	For(i, 1, m) cout << ans[i] << ' ';
	return 0;
}
