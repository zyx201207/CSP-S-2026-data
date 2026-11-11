#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,TT=105;
int c,T,n,k,fa[N],vis[TT],pd[TT],ans;
vector<int>e[N];
int find_set(int x){
	return x==fa[x]?x:fa[x]=find_set(fa[x]);
}
void bfs(int s,int &mx){
	queue<pair<int,int>>q;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(s,0)),vis[s]=1;
	while(!q.empty()){
		pair<int,int>u=q.front();
		q.pop();
		if(pd[u.first]){
			mx=max(mx,u.second);
			break;
		}
		for(int v:e[u.first])
			if(!vis[v])vis[v]=1,q.push(make_pair(v,u.second+1));
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k),ans=N;
		for(int i=2;i<=n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<(1<<n);++i){
			int cnt=0,mx=0;
			for(int j=0;j<n;++j)
				pd[j+1]=i>>j&1,cnt+=pd[j+1];
			if(cnt!=k)continue;
			for(int j=1;j<=n;++j)
				fa[j]=j;
			for(int j=1;j<=n;++j)
				if(pd[j])
					for(int v:e[j]){
						if(pd[v])fa[find_set(v)]=find_set(j);
					}
			cnt=0;
			for(int j=1;j<=n;++j)
				cnt+=(pd[j]&&fa[j]==j);
			if(cnt>2)continue;
			for(int j=1;j<=n;++j)
				if(!pd[j])bfs(j,mx);
			ans=min(ans,mx);
		}
		printf("%d\n",ans);
	}
	return 0;
}

