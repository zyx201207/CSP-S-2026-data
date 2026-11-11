#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=505;
const ll inf=LLONG_MAX;
struct Node{
	int x;ll y;
};
vector<Node> sub[N];
int c,n,m,d,q,w[N]; 
ll g[M][M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a;j<=k;j++){
			ll t;cin>>a>>t;
			sub[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) g[i][j]=inf;
		g[i][i]=0; 
	}
	for(int i=1;i<=m;i++){
		for(Node u: sub[i]){
			for(Node v:sub[i]){
				g[u.x][v.x]=g[v.x][u.x]=min(g[u.x][v.x],u.y+v.y); 
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(g[i][k]==inf) continue;
			for(int j=1;j<=n;j++){
				if(g[k][j]==inf) continue;
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(int i=1,s,t;i<=q;i++){
		ll ans=inf;
		cin>>s>>t;
		for(Node u: sub[s]){
			for(Node v: sub[t]){
				if(g[u.x][v.x]!=inf) ans=min(ans,g[u.x][v.x]+u.y+v.y); 
			}
		}
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
