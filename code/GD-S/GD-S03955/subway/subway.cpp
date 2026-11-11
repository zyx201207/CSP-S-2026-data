#include<bits/stdc++.h>
using namespace std;
long long c;
long long n,m,d,q,vis[25005],w[25005],a[505][25005],t[505][25005],k[505];
vector<long long> g[25005];
void dfs(long long u,long long last){
	for(long long i=0;i<g[u].size();i++){
		if(g[u][i]!=last){
			long long x=g[u][i],y;
			for(long long j=1;j<=k[x];j++){
				if(a[x][j]==u){
					y=j;
					break;
				}
			}
			for(long long j=1;j<=k[x];j++){
				if(a[x][j]!=u){
					long long tmp=t[x][j]+t[x][y];
					if(vis[a[x][j]]>tmp+vis[u])vis[a[x][j]]=tmp+vis[u],dfs(a[x][j],x);
				}
			}
		}
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		for(long long i=1;i<=m;i++){
			vis[i]=LONG_LONG_MAX;
		}
		vis[x]=0;
		dfs(x,-1);
		cout<<w[x]+w[y]+vis[y]<<endl;
	}
	return 0;
}
