#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
const ll N=6e5;
ll c,n,m,d,q,a,t,k,w[N],dist[1000][1000]; 
vector<pair<ll,ll>>v[N];
int main(){	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			for(auto p:v[a])
				dist[p.f][i]=dist[i][p.f]=min(dist[i][p.f],p.s+t);
			v[a].push_back({i,t});
		} 
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		ll ans=1e18;
		cin>>x>>y;
		for(auto l:v[x])
			for(auto r:v[y])
				ans=min(ans,l.s+dist[l.f][r.f]+r.s);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0; 
}
