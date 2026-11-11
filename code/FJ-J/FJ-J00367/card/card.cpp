#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, a[N];
int ans[N], b[N], cnt = 0;
int vis[N];
signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	bool flag = true;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] < a[i-1]) flag = false;
	}
	if(flag){
		for(int i = 2;i <= n;i++) if(a[i] != a[i-1]) cout << i << ' ';
		return 0;
	}
	for(int i = 1;i <= n;i++) {
		memset(vis,0,sizeof vis);
		cnt = 0;
		for(int j = i;j <= n;j++){
			for(int k = 1;k <= cnt;k++) {
				if(b[k] == a[j]){
					cnt = k - 1;
					break;
				}
			}
			
			b[++cnt] = a[j];	 
		}
		//for(int z = 1;z <= cnt;z++) cout << b[z] <<' ';
		//cout << '\n';
		for(int k = 1;k <= cnt;k++) {
			if(vis[b[k]] == 0) ans[b[k]]++;
			vis[b[k]] = 1;
		}
	}
	for(int i = 1;i <= n;i++) if(ans[i] > 0) cout << ans[i] <<' ';
	return 0;
}
