#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N], vis[N], v[N], l = 0, cnt[N], ans[N];

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--){
		if(vis[a[i]]){
			while(v[l] != a[i]){
				vis[v[l]] = 0;
				ans[v[l]] += cnt[v[l]] - i;
				cnt[v[l]] = 0;
				l--;
			}
			vis[v[l]] = 0;
			ans[v[l]] += cnt[v[l]] - i;
			cnt[v[l]] = 0;
			l--;
		}
		l++;
		v[l] = a[i];
		vis[a[i]] = 1;
		cnt[a[i]] = i;
	}
	for(int i = 1; i <= m; i++) ans[i] += cnt[i];
	for(int i = 1; i <= m; i++) cout << ans[i] << " ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
