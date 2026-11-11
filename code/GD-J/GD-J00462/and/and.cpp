#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N], cnt[32], ans;
bool vis[N];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(vis, 1, sizeof(vis));
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		for (int j = 0;j <= 30;j++)if (a[i] & (1LL << j))cnt[j]++;
	}
	for (int j = 30;j >= 0;j--){
		if (cnt[j] >= m){
			ans |= (1 << j);
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1;i <= n;i++){
				if (!vis[i])continue;
				if (!(a[i] & (1LL << j)))vis[i] = 0;
				else{
					for (int k = 0;k <= 30;k++)if (a[i] & (1LL << k))cnt[k]++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
