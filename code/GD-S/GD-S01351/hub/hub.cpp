#include<bits/stdc++.h>
using namespace std;

int cnt,n,k,minn=1e9,used[20],dep[20];
vector<int> e[20],g;

void df(int u,int fa){
	if(used[u]&&!used[fa]) g.push_back(u);
	for(auto v:e[u])if(v!=fa) df(v,u);
}

void fs(int u,int fa,int num){
	if(!used[u])dep[u]=min(dep[u],num);
	for(auto v:e[u])if(v!=fa){
		if(!used[u]) fs(v,u,num+1);
		else fs(v,u,1);
	}
}

void dfs(int x){
	if(x>n){
		if(cnt<k) return;
		memset(dep,0x3f,sizeof(dep));
		int maxn=0;
		g.clear();
		df(1,0);
		if(g.size()>2) return;
		for(auto i:g) fs(i,0,0);
		for(int i = 1;i <= n;i++) if(!used[i]) maxn=max(maxn,dep[i]);
		minn=min(minn,maxn);
		return;
	}
	if(cnt<k){
		cnt++;
		used[x]=1;
		dfs(x+1);
		used[x]=0;
		cnt--;
	}
	dfs(x+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=3){
		while(t--){
			minn=1e9;
			memset(used,0,sizeof(used));
			cin>>n>>k;
			for(int i = 1;i <= n;i++) e[i].clear();
			for(int i = 1,u,v;i < n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
			dfs(1);
			cout<<minn<<'\n';
		}
	}
	return 0;
}
