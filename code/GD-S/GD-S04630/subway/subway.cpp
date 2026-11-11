#include<bits/stdc++.h>
using namespace std;
const int N = 505, maxn = 0x3f3f3f3f;
int c, n, m, d, q;//n为边
int kt[N], tx[N][N], ds[N][N], xl[N][N];//tx线路i到节点j站厅 
int mp[N][N], v[N][N], cnt[N], minn;
void fun(int x){
	for(int i = 1; i <= m; i++){
		ds[x][i] = mp[x][i];
	}
	ds[x][x] = 0;
	v[x][x] = 1;
	minn = maxn;
	int p = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!v[x][j] && minn > mp[x][j]){
				p = j;
				minn = mp[x][j];
			}
		}
		v[x][p] = 1;
		for(int j = 1; j <= n; j++){
			if(!v[x][j] && minn + mp[p][j] < ds[x][j] )
				ds[x][j] = minn + mp[p][j];
		}
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> kt[i];
	int k, u;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> u >> tx[i][u];
			xl[i][u] = 1;
			cnt[u]++;
			if(cnt[u]>=2){
				for(int p = 1; p <= n; p++){
					if(xl[p][u]){
						mp[i][p] = tx[i][u] + tx[p][u];
						mp[p][i] = mp[i][p];
					}
				}
			}
		}
	}
	memset(ds, 0x3f, sizeof(ds));
	for(int i = 1; i <= n; i++){
		fun(i);
	}
	int x[100005], y[100005];
	for(int i = 1; i <= q; i++)
		cin >> x[i] >> y[i];
	int ans = maxn;
	for(int i = 1; i <= q; i++){
		ans = maxn;
		for(int j = 1; j <= n; j++){
			if(xl[j][x[i]]){
				for(int p = 1; p <= n; p++){
					if(xl[p][y[i]] && !ds[j][p] == 0) ans = min(ans, ds[j][p]);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 4
1 2*/
