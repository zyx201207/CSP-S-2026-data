#include<bits/stdc++.h>
using namespace std;
const int N=1005;vector<int>e[N];
int fa[N],dis[N],maxdis[N],res[N];bool book[N];
inline int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
inline void dfs(int u,int f) {
	maxdis[u]=0;res[u]=0;
	for(int v:e[u]) {
		if(v==f)continue;dfs(v,u);res[u]=max(res[u],res[v]);
		res[u]=max(res[u],maxdis[v]+1+maxdis[u]);
		maxdis[u]=max(maxdis[u],maxdis[v]+1);
	}
	return;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,T;scanf("%d %d",&id,&T);
	for(int n,k;T--;) {
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++) {
			scanf("%d %d",&u,&v);
			e[u].push_back(v);e[v].push_back(u);
		}
		if(k==n){puts("0");continue;}
		if(k==n-1){puts("1");continue;}
		if(id<=3) {
			int ans=n;
			for(int S=0;S<(1<<n);S++) {
				for(int i=1;i<=n;i++)fa[i]=i;
				int siz=0;
				for(int i=1;i<=n;i++) {
					if((S>>(i-1))&1){book[i]=true;siz++;}
					else book[i]=false;
				}
				if(siz!=k)continue;
				for(int u=1;u<=n;u++)
					for(int v:e[u])if(book[u]&&book[v])fa[getf(u)]=getf(v);
				int cnt=0;
				for(int i=1;i<=n;i++)
					cnt+=(fa[i]==i&&book[i]);
				if(cnt>2)continue;
				queue<int>que;int lasdis=0;
				memset(dis,0x3f,sizeof(int)*(n+1));
				for(int i=1;i<=n;i++)
					if(book[i]){que.push(i);dis[i]=0;}
				for(;!que.empty();) {
					int u=que.front();que.pop();lasdis=dis[u];if(lasdis>=ans)break;
					for(int v:e[u])if(dis[v]>dis[u]+1){dis[v]=dis[u]+1;que.push(v);}
				}
				ans=min(ans,lasdis);
			}
			printf("%d\n",ans);continue;
		}
		if(k==2) {//WA
			int ans=n;
			for(int rt=1;rt<=n;rt++) {
				for(int u:e[rt])dfs(u,rt);
				int maxx=0,secmax=0;
				for(int u:e[rt]) {
					if(res[u]>maxx){secmax=maxx;maxx=res[u];}
					else secmax=max(secmax,res[u]);
				}
				ans=min(ans,max((maxx+1)/2,secmax));
			}
			printf("%d\n",ans);continue;
		}
	}
	return 0;
}
