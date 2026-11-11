#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6e5;
const ll inf = 1e17;

ll w[N];
vector<pair<int,int> >G[N];ll a[N],b[N];vector<int>V;
ll f[600][600];int c,n,m,d,q;
void solve(){
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			f[i][j]=f[j][i]=inf;
	for(int i = 1;i<=n;i++) f[i][i]=0;
	for(int i = 1;i<=m;i++){
		V.clear();
		for(int j = 0;j<G[i].size();j++){
			int v=G[i][j].first,l=G[i][j].second;
			a[v]=l;V.push_back(v);
		}
		for(int j = 0;j<V.size();j++){
			for(int k=0;k<j;k++){
				int u=V[j],v=V[k];
				f[u][v]=min(f[u][v],a[u]+a[v]);
				f[v][u]=min(f[v][u],a[u]+a[v]);
			}
		}
	}
}
void floyd(){
	for(int k = 1;k<=n;k++){
		for(int i =1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=min(f[i][j],f[j][k]+f[k][i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		cin>>b[i];
		for(int j = 1;j<=b[i];j++){
			int v,l;cin>>v>>l;
			G[v].push_back({i,l});
		}
	}
	solve();
	floyd();
	while(q--){
		int x,y;cin>>x>>y;ll ans=inf;
		for(int i =0;i<G[x].size();i++){
			ll v1=G[x][i].first,l1=G[x][i].second;
			for(int j = 0;j<G[y].size();j++){
				ll v2=G[y][j].first,l2=G[y][j].second;
				ans=min(ans,f[v1][v2]+l1+l2);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
