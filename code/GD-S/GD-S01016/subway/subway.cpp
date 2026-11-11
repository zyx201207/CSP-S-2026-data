#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
#define ft first
#define sd second
inline int read(){char ch=getchar();int f=1,x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return f*x;}
const int N=1e6+5,M=505,inf=1e18;
int c_id,n,m,d,q;
int W[N];
vector<pair<int,int>>vec[N];
int dis[M][M];
signed main(){
	File("subway");
	c_id=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		W[i]=read();
	for(int i=1,k,u,w;i<=n;i++){
		k=read();
		while(k--)
			u=read(),w=read(),vec[u].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:inf);
	for(int i=1;i<=m;i++)
		for(auto p:vec[i])
			for(auto p2:vec[i]){
				int u=p.ft,v=p2.ft,w=p.sd+p2.sd;
				dis[u][v]=min(dis[u][v],w),dis[v][u]=min(dis[v][u],w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	while(q--){
		int st=read(),ed=read();
		int ans=inf;
		for(auto p:vec[st])
			for(auto p2:vec[ed]){
				int u=p.ft,v=p2.ft,w=p.sd+p2.sd;
				ans=min(ans,dis[u][v]+w+W[st]+W[ed]);
			}
		cout<<ans<<"\n";
	}
	return 0;
}