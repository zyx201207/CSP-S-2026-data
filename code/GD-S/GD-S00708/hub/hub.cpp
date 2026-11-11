#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,T;
int n,m;
vector<int> v[MAXN];
int fa[MAXN];
int f[MAXN];
int dis[MAXN];
int dep[MAXN];
bool vis[MAXN];
bool flag[MAXN];
int s,t;
queue<int> q;
void init(){
	for(int i=1;i<=n;i++){
		v[i].clear();
	}
}
void dfs1(int d,int fat){
	fa[d]=fat;
	for(int i=0;i<v[d].size();i++){
		int tmp=v[d][i];
		if(tmp==fat){
			continue;
		}
		dfs1(tmp,d);
	}
}
void dfs2(int d,int fa,int y,int w){
	dep[d]=0;
	f[d]=1;
	for(int i=0;i<v[d].size();i++){
		int tmp=v[d][i];
		if(tmp==fa||tmp==y){
			continue;
		}
		dfs2(tmp,d,y,w);
		if(dep[tmp]+1>w){
			f[d]+=f[tmp];
		}
		dep[d]=max(dep[d],dep[tmp]+1);
	}
}
void bfs(int x,int y){
	for(int i=1;i<=n;i++){
		dis[i]=-1;
	}
	dis[x]=0;
	q.push(x);
	while(!q.empty()){
		int d=q.front();
		q.pop();
		vis[d]=true;
		for(int i=0;i<v[d].size();i++){
			int tmp=v[d][i];
			if(tmp==y||dis[tmp]!=-1){
				continue;
			}
			dis[tmp]=dis[d]+1;
			q.push(tmp);
		}
	}
	if(!s){
		for(int i=1;i<=n;i++){
			if(vis[i]&&dis[i]>=dis[s]){
				s=i;
			}
		}
	}
	else if(!t){
		for(int i=1;i<=n;i++){
			if(vis[i]&&dis[i]>=dis[t]){
				t=i;
			}
		}
	}
}
int solve(int x,int y,int w){
	for(int i=1;i<=n;i++){
		vis[i]=false;
	}
	s=t=0;
	bfs(x,y);
	bfs(s,y);
	int st;
	for(int i=1;i<=n;i++){
		flag[i]=false;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]&&dis[i]==dis[t]/2){
			flag[i]=true;
		}
	}
	bfs(t,y);
	for(int i=1;i<=n;i++){
		if(vis[i]&&flag[i]&&dis[i]==(dis[s]+1)/2){
			st=i;
		}
	}
	dfs2(st,0,y,w);
	return f[st];
}
bool check(int x){
	int ans=n;
	for(int i=2;i<=n;i++){
		ans=min(ans,solve(i,fa[i],x)+solve(fa[i],i,x));
	}
	return ans<=m;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		printf("%d\n",l);
	}
}
