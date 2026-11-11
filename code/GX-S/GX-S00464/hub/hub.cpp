#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int maxn=1e5+10;
int c,t,n,k,u,v,dis[maxn],fat[maxn],ans;
bool col[maxn];
vector<int>g[maxn];
map<pii,bool>mp;
int getfa(int x){
	return fat[x]==x?fat[x]:fat[x]=getfa(fat[x]);
}
void uniona(int x,int y){
	x=getfa(x),y=getfa(y);
	if(x!=y)
		fat[x]=y;
}
void dfs(int x,int fa){
	dis[x]=min(dis[x],dis[fa]+1);
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==fa)
			continue;
		dfs(to,x);
	}
}
void DFS(int x,int s){
	if(x==n+1){
		if(s!=k)
			return;
		int cnt=0,pus=0;
		vector<int>vec;
		for(int i=1;i<=n;i++)
			fat[i]=i;
		for(int i=1;i<=n;i++)
			if(col[i])
				vec.push_back(i);
		for(int i=0;i<vec.size();i++){
			int u=vec[i];
			for(auto v:vec)
				if(mp[make_pair(u,v)])
					uniona(u,v);
		}
		for(int i=1;i<=n;i++)
			if(col[i]&&getfa(i)==i)
				cnt++;
		if(cnt>2)
			return;
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++)
			if(col[i])
				dis[i]=0;
		for(int i=1;i<=n;i++)
			if(col[i])
				dfs(i,0);
		for(int i=1;i<=n;i++)
			pus=max(pus,dis[i]);
		//cout<<pus<<" "<<"\n";
		ans=min(ans,pus);
		return;
	}
	if(s==k&&x<n+1)
		DFS(n+1,s);
	else if(s>k)
		return;
	else if(s<k&&n-x+1+s<k)
		return;
	col[x]=true;
	DFS(x+1,s+1);
	col[x]=false;
	DFS(x+1,s);
}
void work(){
	mp.clear();
	ans=0x3f3f3f3f;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		mp[make_pair(u,v)]=mp[make_pair(v,u)]=true;
	}
	DFS(1,0);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		g[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		work();
	return 0;
}
