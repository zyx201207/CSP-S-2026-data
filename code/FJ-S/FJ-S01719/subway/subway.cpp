#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1024,M=5e5+5;
int c,n,m,d,q;
int val[M],dist[N][N];
vector<pair<int,int> >way[M];
int read(){
	int d=0,f=1;
	char c=getchar();
	while(c!=EOF&&(c<'0'||c>'9')){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c!=EOF&&('0'<=c&&c<='9')){
		d=d*10+(c-'0');
		c=getchar();
	}
	return d*f;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)val[i]=read();
	for(int u=1,k;u<=n;u++){
		k=read();
		for(int j=1,v,w;j<=k;j++){
			v=read();w=read();
			way[v].push_back({u,w});
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int k=1;k<=m;k++){
		for(int i=0,u,valu;i<way[k].size();i++){
			u=way[k][i].first,valu=way[k][i].second;
			for(int j=0,v,valv;j<way[k].size();j++){
				v=way[k][j].first,valv=way[k][j].second;
				dist[u][v]=min(dist[u][v],valu+valv);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int x,y,ans=1e18;
		x=read();y=read();
		for(int i=0,u,valu;i<way[x].size();i++){
			u=way[x][i].first,valu=way[x][i].second;
			for(int j=0,v,valv;j<way[y].size();j++){
				v=way[y][j].first,valv=way[y][j].second;
				ans=min(ans,dist[u][v]+valu+valv);
			}
		}
		cout<<ans+val[x]+val[y]<<'\n';
	}
	return 0;
}
