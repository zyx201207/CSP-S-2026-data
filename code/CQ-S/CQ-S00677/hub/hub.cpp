#include<bits/stdc++.h>
#define ppcnt __builtin_popcount
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=1e6+5;
int optt,T;
int n,k;
vector<int>G[Maxn];
namespace sub1{
	int ans;
	int dis[105][105];
	int fa[114];
	struct edge{
		int u,v;
	}e[114];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline void sol(){
		n=read();k=read();
		ans=n;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=n+1;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			e[i]={u,v};
			dis[u][v]=dis[v][u]=1;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
		for(int s=1;s<(1<<n);s++){
			if(ppcnt(s)!=k)continue;
			for(int i=1;i<=n;i++)fa[i]=i;
			for(int i=1;i<n;i++){
				int u=e[i].u,v=e[i].v;
				if((s>>u-1&1)&&(s>>v-1&1))fa[find(u)]=find(v);
			}
			int cnt=0;
			for(int i=1;i<=n;i++)if(s>>i-1&1)cnt+=(find(i)==i);
			if(cnt>2)continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int val=n;
				for(int j=1;j<=n;j++)if(s>>j-1&1)val=min(val,dis[i][j]);
				res=max(res,val);
			}
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
	inline void solve(){
		while(T--)sol();
	}
}
namespace sub_k2{
	int ans;
	int dep[Maxn],fa[Maxn];
	void dfs1(int u,int v){
		dep[u]=dep[v]+1;fa[u]=v;
		for(int y:G[u])if(y!=v){
			dfs1(y,u);
		}
	}
	inline void sol(){
		n=read();k=read();
		ans=0;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			G[u].push_back(v);G[v].push_back(u);
		}
		dep[0]=-1;dfs1(1,0);
		int rt=0;
		for(int i=1;i<=n;i++)if(dep[i]>dep[rt])rt=i;
		dfs1(rt,0);
		for(int i=1;i<=n;i++)ans=max(ans,dep[i]);
		ans=max(1,(ans+3)/4);
		printf("%d\n",ans);
	}
	inline void solve(){
		while(T--)sol();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	optt=read();T=read();
	if(optt<=3)sub1::solve(),exit(0);
	if(optt==7||optt==11||optt==12)sub_k2::solve(),exit(0);
	return 0;
}
/*
1 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
