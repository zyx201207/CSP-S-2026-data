#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],dis[N][N];
struct node{int to,t;};
vector<node> pt[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,p,t;j<=k;j++){
			cin>>p>>t;
			for(auto x:pt[p]){
				dis[x.to][i]=min(dis[x.to][i],t+x.t);
				dis[i][x.to]=min(dis[i][x.to],t+x.t);
			}	
			pt[p].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int u,v,ans=1e18;
		cin>>u>>v;
		for(auto i:pt[u])
			for(auto j:pt[v])
				ans=min(ans,i.t+j.t+dis[i.to][j.to]);
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
