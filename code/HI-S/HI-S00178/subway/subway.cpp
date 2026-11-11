#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=510,M=5e5+10,INF=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,x,y,ans;
ll w[M];
vector<ll> a[N],t[N],e[M];
ll g[N][N];
map<pair<ll,ll>,ll> id;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++) cin >> w[i];
	for(int i = 1,k;i<=n;i++){
		cin >> k;
		for(int j = 0,aa,tt;j<k;j++){
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			e[aa].push_back(i);
			id[{i,aa}]=j;
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i = 1;i<=n;i++) g[i][i]=0;
	for(int i = 1;i<=m;i++){
		ll E=e[i].size();
		for(int u = 0;u<E-1;u++){
			for(int v = u+1;v<E;v++){
				g[e[i][u]][e[i][v]]=g[e[i][v]][e[i][u]]=min(g[e[i][u]][e[i][v]],t[e[i][u]][id[{e[i][u],i}]]+t[e[i][v]][id[{e[i][v],i}]]);
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(g[i][k]+g[k][j]<INF){
					g[i][j]=g[j][i]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
	}
	while(q--){
		cin >> x >> y;
		ll X=e[x].size(),Y=e[y].size();
		ans=INF;
		for(int u = 0;u<X;u++){
			for(int v = 0;v<Y;v++){
				ans=min(ans,g[e[x][u]][e[y][v]]+t[e[x][u]][id[{e[x][u],x}]]+t[e[y][v]][id[{e[y][v],y}]]+w[x]+w[y]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

