#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500005],dis[505][505];
struct csb{
	int v,w;
};
vector<csb>e[500505];
int read(){
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*y;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		dis[i][i]=0;
		while(k--){
			int y=read()+n,z=read();
			e[i].push_back({y,z});
			for(int j=0;j<e[y].size();j++)
				dis[i][e[y][j].v]=dis[e[y][j].v][i]=min(dis[i][e[y][j].v],z+e[y][j].w);
			e[y].push_back({i,z});
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(i!=k)
				for(int j=i+1;j<=n;j++)
					if(j!=k)
						dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x=read(),y=read(),ans=LONG_LONG_MAX;
		for(int i=0;i<e[x+n].size();i++)
			for(int j=0;j<e[y+n].size();j++)
				ans=min(ans,e[x+n][i].w+e[y+n][j].w+dis[e[x+n][i].v][e[y+n][j].v]);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
