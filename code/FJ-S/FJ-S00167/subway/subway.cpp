#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+10;
struct Node{
	ll to,w;
	Node(ll a=0,ll b=0):to(a),w(b){}
};
ll f[N][N];
ll w[M];
vector<Node>g[M];
ll n,m,c,d,q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll a,b;
			cin>>a>>b;
			g[a].push_back(Node(i,b));
		//	cout<<a<<' '<<i<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j].to,v=g[i][k].to;
				f[u][v]=f[v][u]=g[i][j].w+g[i][k].w;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(int i=0;i<g[u].size();i++){
			for(int j=0;j<g[v].size();j++){
				Node x=g[u][i],y=g[v][j];
				ll u1=x.to,v1=y.to;
				ll ww1=x.w,ww2=y.w;
				ans=min(ans,f[u1][v1]+ww1+ww2);
			//	cout<<u1<<' '<<v1<<'\n';
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}


