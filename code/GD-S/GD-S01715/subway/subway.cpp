#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define rep(i,l,r) for(ri i=l;i<=r;i++)
#define per(i,r,l) for(ri i=r;i>=l;i--)
#define inl inline
#define N 505
#define M 1600005
int c, n, m, d, q, tot;
int W[5005];
int dist[5005][5005];
signed main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> W[i];
	int a, t, last = 0;
	rep(i, 1, 3005) rep(j, 1, 3005) dist[i][j] = 1e18;
	tot = 2 * m;
	rep(i, 1, m){
		dist[i][i + m] = dist[i + m][i] = W[i]; 
	}
	int k;
	rep(i, 1, n){
		cin >> k;
		rep(j, 1, k){
			cin >> a >> t;
			++ tot;
			dist[tot][a + m] = dist[a + m][tot] = t;
			if(j != 1) dist[tot - 1][tot] = dist[tot][tot - 1] = 0;
		}
	}
	rep(i, 1, tot){
		dist[i][i] = 0;
	}
//	cout << tot << endl;
	rep(k, 1, tot){
		rep(i, 1, tot){
			if(i == k) continue;
			rep(j, 1, tot){
				if(i == j || k == j) continue;
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}
//	rep(i, 1, tot){
//		rep(j, 1, tot){
//			cout << dist[i][j] << " ";
//		}
//		cout << endl;
//	}
	int x, y;
	while(q--){
		cin >> x >> y;
		cout << dist[x][y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
