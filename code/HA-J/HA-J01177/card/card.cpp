#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
bool vis[505];
int a[505], last[505], answ[505];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) {
		memset(vis, 0, sizeof(vis));
		memset(last, 0, sizeof(vis));
		for(int j = i;j <= n;j++) {
			if(last[a[j]] && !vis[last[a[j]]]) {
				for(int k = last[a[j]];k < j;k++) vis[k] = 1;
			}
			last[a[j]] = j;
		}
		for(int j = i;j <= n;j++) {
			if(!vis[j]) answ[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++) cout << answ[i] << " ";
	return 0;
}
