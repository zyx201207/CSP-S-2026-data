#include<bits/stdc++.h>
using namespace std;

#define N 15
#define ll long long
#define INF 0x3f3f3f3f

int c,t;

vector<int> edge[N];

int ans=0x3f3f3f3f;

vector<int> use;
int n,k;

bool vis[N];
int len[N];

bool find(int i){
	//cout<<"do: "<<i<<'\n';//debug
	for(auto s:use){
		if(s==i){
			return 1;
		}
	}
	return 0;
}

void bfs1(int u){
	vis[u]=true;
	if(find(u))len[u]=0;
	for(auto v:edge[u]){
		if(!vis[v] && find(u)){
			bfs1(v);
		}
	}
	return;
}
void minfcing(int u,int fa){
	for(auto v:edge[u]){
		if(v==fa) continue;
		len[v]=min(len[v],len[u]+1);
		minfcing(v,u);
	}
	return ;
}
int bfs2(int u){
	int minn=INF;
	vis[u]=true;
	for(auto v:edge[u]){
		if(len[v]==0){
			len[u]=1;
			return 1;
		}
		if(!vis[v]){
			minn=min(minn,bfs2(v)+1);
			//cout<<"minn: "<<minn<<'\n';//debug
		}
	}
	len[u]=minn;
	minfcing(u,-1);
	return minn;
}

void check(){
	//先检查连通块个数是否合法 
	int kuai=0;
	memset(vis,false,sizeof vis);
	memset(len,INF,sizeof len);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(find(i)){
				kuai++;
				bfs1(i);
			}
		}
	}
	if(kuai>2){
		return;
	}
	
	//块的数量满足条件，bfs求最小半径
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(!find(i)){
				bfs2(i);
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		if(!find(i)){
			maxx=max(maxx,len[i]);
			//cout<<len[i]<<" ";//debug
		}
	}
	//cout<<maxx<<'\n';//debug
	ans=min(ans,maxx);
	return;
}

void dfs(int dep){
	if(use.size()==k){
		for(auto u:use) //cout<<u<<' ';//debug;
		//cout<<'\n';//debug
		check();
		return;
	}
	if(dep>n || use.size()>k){
		return;
	}
	dfs(dep+1);
	use.push_back(dep);
	dfs(dep+1);
	use.pop_back();
	return;
}

void solve(){
	ans=INF;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		edge[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1);
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("hub.in","r",stdin);// freopen("mirage.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
枚举每个选/不选，验证用广搜
我一定是发烧了
现在怎么求连通块个数
也用bfs 
*/

