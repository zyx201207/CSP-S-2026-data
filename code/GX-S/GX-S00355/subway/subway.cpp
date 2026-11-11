#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
const int N=5*100001;
int gm;
int n,m,d,q;
LL w[N],p[N];
struct station{
	int l,t;
}s[N][31];
LL dis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&gm,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int i=1;i<=m;i++)	scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int st,ti;
			scanf("%d%d",&st,&ti);
			s[st][++p[st]]=(station){i,ti};
		}
	}
	for(int i=1;i<=m;i++){
		int x=p[i];
		if(x<=1)	continue;
		for(int j=1;j<x;j++)
			for(int k=j+1;k<=x;k++){
				int u=s[i][j].l,v=s[i][k].l;
				int t1=s[i][j].t,t2=s[i][k].t;
				dis[u][v]=dis[v][u]=min((LL)dis[u][v],(LL)(t1+t2));
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && i!=k && j!=k)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	while(q--){
		int u,v;
		LL ans=1e18;
		cin>>u>>v;
		int x1=p[u],x2=p[v];
		for(int i=1;i<=x1;i++)
			for(int j=1;j<=x2;j++){
				int l1=s[u][i].l,l2=s[v][j].l;
				int t1=s[u][i].t,t2=s[v][j].t;
				ans=min((LL)ans,(LL)(w[u]+t1)+dis[l1][l2]+(t2+w[v]));
			}
		printf("%lld\n",ans);
	}
	return 0;
}
