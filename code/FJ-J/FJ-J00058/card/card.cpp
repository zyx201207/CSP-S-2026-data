#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 5e5 + 5, M = 3e5 + 5;

int n, m, t, a[N], f[N], cnt[M], lst[M], ans[M]; 
bool vis[M];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		lst[a[i]] = i, cnt[a[i]]++;
	}
	for(int i = 1; i <= n; i++) f[i] = lst[a[i]];
	for(int i = 1; i <= m; i++) {
		if(!vis[i]) {
			++t;
			int sum = 0, now = lst[i];
			bool ok = false;
			while(now <= n) {
				if(!vis[a[now]]) sum += cnt[a[now]]; 
				vis[a[now]] = true;
				if(now == lst[a[now]]) {
					ans[a[now]] += sum, now++;
				} else {
					now = f[now];
				}
				if(now == n && !ok) ok = true;
				else if(now == n) break;
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T = 1;
//	cin >> T;
	while(T--) solve();

	return 0;
}

