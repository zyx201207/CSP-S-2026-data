#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i=a; i<=b; ++i)
#define F_(i,a,b) for(int i=a; i>=b; i--)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fr first
#define sc second
#define pb push_back
const int N = 5e5+10, M = 1e6+10, K = 510;
const ll INF = 1e18;
int _,n,m,d,q,nn,cnt[N];
ll ar[N],dis[K][K];
pil ln[N][21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> _ >> m >> n >> d >> q;
	F(i,1,n) cin >> ar[i];
	F(i,1,m){
		int k; cin >> k;
		F(j,1,k){
			int u; ll t;
			cin >> u >> t;
			ln[u][++cnt[u]] = {i,t};
		}
	}
	F(i,1,m) F(j,1,m) if (i != j) dis[i][j] = INF;
	F(i,1,n){
		F(x,1,cnt[i]){
			F(y,x+1,cnt[i]){
				int u = ln[i][x].fr, v = ln[i][y].fr; ll w = ln[i][x].sc+ln[i][y].sc;
				dis[u][v] = min(dis[u][v],w), dis[v][u] = min(dis[v][u],w);	
			}
		}
	}
	F(k,1,m) F(i,1,m) F(j,1,m) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	while (q--){
		int x,y;
		cin >> x >> y;
		ll ans = INF;
		F(a,1,cnt[x]){
			F(b,1,cnt[y]){
				int u = ln[x][a].fr, v = ln[y][b].fr; ll w = ln[x][a].sc+ln[y][b].sc;
				ans = min(ans, dis[u][v]+w+ar[x]+ar[y]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
