#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005][31],vis[200005], ans, mx, flg;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		int x;
		cin >> x;
		for(int j = 30;j >= 0;j --){
			a[i][j] = (x >> j & 1);
			if(a[i][j] == 1) mx = max(mx, j);
		}
	}
	flg = 1;
	for(int j = mx;j >= 0;j --){
		int cnt = 0;
		for(int i = 1;i <= n;i ++){
			cnt += (!vis[i] && a[i][j]);
			if(!a[i][j]) vis[i] = 1;
		}
		if(cnt >= m){
			ans += (1 << j);
			flg = 0;
		}
		if(flg){
			for(int i = 1;i <= n;i ++) vis[i] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
