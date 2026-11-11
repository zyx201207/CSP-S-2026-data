#include <bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
//head
const int N=505,M=5e5+5;
const ll INF=2e18;
int w[M],k[N];
vector<vector<PII>> a(N),G(M);
ll G1[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i].pb({x,y}),G[x].pb({i,y});
		}
	}
	memset(G1,0x3f,sizeof(G1));
	for(int i=1;i<=n;i++) G1[i][i]=0;
	for(int i=1;i<=n;i++){
		for(auto it:a[i]){
			for(auto itt:G[it.fi]){
				if(i==itt.fi) continue;
				G1[i][itt.fi]=G1[itt.fi][i]=min(G1[i][itt.fi],(ll)(it.se+itt.se));
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G1[i][j]=min(G1[i][j],G1[i][k]+G1[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;cin>>x>>y;
		ll ans=INF;
		for(auto u:G[x]){
			for(auto v:G[y]){
				ans=min(ans,(ll)(G1[u.fi][v.fi]+w[x]+u.se+w[y]+v.se));
			}
		}
		cout<<ans<<'\n';
	}
}
