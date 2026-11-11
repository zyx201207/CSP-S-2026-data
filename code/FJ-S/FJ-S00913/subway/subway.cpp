#include<cstdio>
#include<vector>
typedef long long LL;
const int N=510,M=5e5+10;
const LL inf=0x3f3f3f3f3f3f3f3fLL;
int c,n,m,d,q;
LL ans;
LL w[M];
LL dis[N][N];
struct Node{
	int id;
	LL t;
};
std::vector<Node> a[M];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
template<typename T>inline T min(T a,T b){return a<b?a:b;}
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i)
		w[i]=read();
	for(int i=1,u;i<=n;++i)for(int j=read();j;--j)
		u=read(),a[u].push_back((Node){i,read()});
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(i!=j)
		dis[i][j]=inf;
	for(int i=1;i<=m;++i)for(Node u:a[i])for(Node v:a[i])if(u.id!=v.id)
		dis[u.id][v.id]=dis[v.id][u.id]=min(dis[u.id][v.id],u.t+v.t);
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)if(i!=k)for(int j=1;j<=n;++j)if(i!=j&&j!=k)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int _=1,u,v;_<=q;++_){
		u=read(),v=read(),ans=inf;
		for(Node i:a[u])for(Node j:a[v])
			ans=min(ans,i.t+j.t+dis[i.id][j.id]);//,printf("%d %d %lld\n",i.id,j.id,i.t+j.t+dis[i.id][j.id]);
		printf("%lld\n",w[u]+w[v]+ans);
	}
	return 0;
}
/*
15:24 O(n^3 + d sum(k) + qd^2) 100 pts
*/
