#include<bits/stdc++.h>
using namespace std;

int c,t;

int n,k;

vector<int> g[512345];

int u,v;

bool chosen[512345];

int res[512345];

bool vis[512345];

int minn=0x3f3f3f3f;

int dfs2(int x,int fa){
	vis[x]=true;
	for(int i=0;i<(int)g[x].size();i++){
		if(g[x][i]==fa||!chosen[g[x][i]]){
			continue;
		}
		dfs2(g[x][i],x);
	}
	return 54250;
}

int dfs3(int x,int fa){
	if(chosen[x]){
		return 1;
	}
	for(int i=0;i<(int)g[x].size();i++){
		if(g[x][i]==fa){
			continue;
		}
		int ress=dfs3(g[x][i],x);
		if(ress){
			return ress+1;
		}
	}
	return 0;
}

void dfs(int x){
	if(x==k){
		for(int i=1;i<=n;i++){
			vis[i]=false;
		}
		int maxn=0,cnt=0;
		for(int i=0;i<k;i++){
			if(!vis[res[i]]){
				dfs2(res[i],-1);
				cnt++;
			}
		}
		if(cnt>2){
			return;
		}
		for(int i=1;i<=n;i++){
			maxn=max(maxn,dfs3(i,-1)-1);
		}
		minn=min(minn,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!chosen[i]){
			chosen[i]=true;
			res[x]=i;
			dfs(x+1);
			chosen[i]=false;
		}
	}
	return;
}

void sol(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	cout<<minn<<"\n";
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		sol();
	}
	return 0;
}
