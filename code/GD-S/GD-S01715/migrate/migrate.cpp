#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define rep(i,l,r) for(ri i=l;i<=r;i++)
#define per(i,r,l) for(ri i=r;i>=l;i--)
#define inl inline
#define N 505
int c, t;
int n, d;
int a[N];
int dist[N][N];
int ans[N][N];
inl void work(){
	cin >> n >> d;
	rep(i, 1, n) cin >> a[i];
	memset(dist,0x3f,sizeof(dist));
	rep(i, 1, n) rep(j, 1, n) ans[i][j] = 1;
	rep(i, 1, n){
		dist[i][i] = 0;
		rep(j, i + 1, n){
			if(abs(a[i] - a[j]) <= d) dist[i][j] = dist[j][i] = 1;
		}
	}
	int tot = n;
	rep(k, 1, tot){
		rep(i, 1, tot){
			if(i == k) continue;
			rep(j, 1, tot){
				if(i == j || k == j) continue;
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					ans[i][j] = 1;
				}
				else if(dist[i][j] == dist[i][k] + dist[k][j]){
					ans[i][j] ++;
				}
			}
		}
	}
	int cnt = 0;
	rep(i, 1, n){
		rep(j, i + 1, n){
			if(ans[i][j] == 2) cnt ++;
//			cout << ans[i][j] << " ";
		}
//		cout << endl;
	}
	cout << cnt << endl;
}
signed main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		work();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
