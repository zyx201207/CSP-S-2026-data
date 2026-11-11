#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=300+10;
int c, T;
int n;
LL d, ans=0;
LL a[maxn];
int minn[maxn][maxn];
int cnt[maxn][maxn];
void dfs(int sx, int nx, int fx, int step){
	if(nx==fx){
		if(step<minn[sx][fx]){
			minn[sx][fx]=step;
			cnt[sx][fx]=0;
		}else if(step==minn[sx][fx]){
			minn[sx][fx]++;
		}
		return ;
	}
	for(int i=1;i+nx<=fx;i++){
		if(a[nx+i]-a[nx]<=d)dfs(sx, nx+i, fx, step+1);
		else break;
	}
	return ;
}
void solve(){
	memset(minn, 0x3f, sizeof(minn));
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> d;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i-1;j++){
			dfs(j, j, i, 0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i-1;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	cout << ans << '\n';
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> T;
	
	while(T--){
		solve();
	}
	return 0;
}
