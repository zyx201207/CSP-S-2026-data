#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=505;
const long long inf=1e18;
int c,n,m,d,q,w[N];long long dist[M][M];
struct Node{
	int u,v;
};
vector<Node> a[M],g[N];
bool cmp(Node x,Node y){
	return x.u<y.u;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1,u,v;j<=k;j++){
			cin>>u>>v;
			g[u].push_back({i,v});
			a[i].push_back({u,v});
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int pos1=0,l1=a[i].size(),l2=a[j].size();
			for(int pos2=0;pos2<l2;pos2++){
				while(a[i][pos1].u<a[j][pos2].u&&pos1<l1)pos1++;
				if(pos1==l1)break;
				if(a[i][pos1].u==a[j][pos2].u)dist[j][i]=dist[i][j]=min(dist[i][j],1ll*a[i][pos1].v+a[j][pos2].v);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int l,r;long long ans=inf;cin>>l>>r;
		for(int i=0;i<g[l].size();i++){
			for(int j=0;j<g[r].size();j++){
				ans=min(ans,dist[g[l][i].u][g[r][j].u]+g[l][i].v+g[r][j].v+w[l]+w[r]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}