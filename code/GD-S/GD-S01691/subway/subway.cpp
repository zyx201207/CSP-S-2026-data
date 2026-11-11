#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10,M=1e3+10;
struct node{
	ll x;
	int id;
	bool operator<(const node c)const{return x>c.x;}
};
int c[N],b[N][22],g[M][M],bj[M];
ll dis[M][M],s[N][22],g1[M][M];
priority_queue<node> q;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cid=read(),n=read(),m=read(),d=read(),p=read(),u,v,k;
	ll w;
	for(int i=1;i<=m;i++) c[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++)
			v=read(),w=read(),b[v][++b[v][0]]=i,s[v][++s[v][0]]=w;	
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=b[i][0];j++)
			for(int z=j+1;z<=b[i][0];z++){
				u=b[i][j],v=b[i][z];
				if(!g1[u][v])
					g[u][++g[u][0]]=v,g[v][++g[v][0]]=u,g1[u][v]=g1[v][u]=s[i][j]+s[i][z];
				else g1[u][v]=g1[v][u]=min(g1[u][v],s[i][j]+s[i][z]);
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18,bj[j]=0;
		dis[i][i]=0,q.push({0ll,i});
		while(!q.empty()){
			u=q.top().id,q.pop();
			if(bj[u]) continue;
			bj[u]=1;
			for(int j=1;j<=g[u][0];j++){
				v=g[u][j],w=g1[u][v];
				if(dis[i][u]+w<dis[i][v])
					dis[i][v]=dis[i][u]+w,q.push({dis[i][v],v});
			}
		}
	}
	for(int i=1;i<=p;i++){
		u=read(),v=read();
		ll ans=1e18;
		for(int j=1;j<=b[u][0];j++)
			for(int z=1;z<=b[v][0];z++)
				ans=min(ans,s[u][j]+s[v][z]+dis[b[u][j]][b[v][z]]+c[u]+c[v]);
		write(ans),putchar('\n');
	}
	return 0;
}
