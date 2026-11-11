#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int M=6e5;
const int N=500;
const ll inf=1e18;

struct Edge{
	ll v,w;
};

ll _,n,m,d;
ll w[M+10];
ll k[N+10];
ll f[N+10][N+10];
vector<int> a[N+10];
vector<Edge> G[M+10];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>_>>n>>m>>d>>_;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x,w;
			cin>>x>>w;
			a[i].push_back(x);
			G[i+m].push_back({x,w});
			G[x].push_back({i+m,w});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
		f[i][i]=0;
	}
	
	for(int i=1;i<=m;i++){
		for(auto X:G[i]){
			for(auto Y:G[i]){
				int u=X.v,v=Y.v;
				if(u==v) continue;
				f[u-m][v-m]=min(f[u-m][v-m],X.w+Y.w);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	while(_--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto X:G[x]){
			for(auto Y:G[y]){
				int u=X.v-m;
				int v=Y.v-m;
				ans=min(ans,w[x]+w[y]+X.w+Y.w+f[u][v]);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
