#include<bits/stdc++.h>
#define N 510
#define M 500010
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3fll
#define ull unsigned long long
#define pii pair<int,int>
#define lowbit(x) (x&-x)
using namespace std;
ll dst[N][N];
int _,n,m,d,q;
vector<int> a[M];vector<ll> t[M];
int k[M];
ll w[M];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin >> _ >> n >> m >> d >> q; 
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j)dst[i][j] = INF;
	}
	for(int i = 1;i <= m;++i)cin >> w[i];
	for(int i = 1;i <= n;++i){
		dst[i][i] = 0;
		int k;cin >> k;
		while(k--){
			int av;ll tv;cin >> av >> tv;
			a[av].emplace_back(i),t[av].emplace_back(tv);
		}
	}
	// 对于每一个都做一遍
	for(int i = 1;i <= m;++i){
		int sze = a[i].size();
		for(int j = 0;j < sze;++j){
			for(int y = j+1;y < sze;++y){
				dst[a[i][j]][a[i][y]] = min(dst[a[i][j]][a[i][y]],t[i][j]+t[i][y]);
				dst[a[i][y]][a[i][j]] = min(dst[a[i][y]][a[i][j]],t[i][j]+t[i][y]);
			}
		}
	}
//	for(int i = 1;i <= n;++i){
//		for(int j = 1;j <= n;++j)printf("[%lld]",dst[i][j]);
//		printf("\n");
//	}
	// floyd
	for(int i = 1;i <= n;++i){
		for(int k = 1;k <= n;++k){
			for(int j = 1;j <= n;++j)dst[i][j] = min(dst[i][k]+dst[k][j],dst[i][j]);
		}
	}
	// answer
	while(q--){
		int x,y;ll ans = INF;
		cin >> x >> y;
		int sx = a[x].size(),sy = a[y].size();
		// all my stages
		for(int i = 0;i < sx;++i){
			for(int j = 0;j < sy;++j){
				ans = min(ans,t[x][i]+t[y][j]+dst[a[x][i]][a[y][j]]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	} 
	return 0;
} 
/*



*/
