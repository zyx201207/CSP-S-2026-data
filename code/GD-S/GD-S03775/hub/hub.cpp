#include<bits/stdc++.h>
using namespace std;
#define FILE "hub"
int n,k;
vector<int> G[5001];
bool vis[5001];
int fa[5001];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)	return;
	fa[u]=v;
}
int ch[5001];
int ans;
int llca[5001][5001],ffa[5001][15],dep[5001];
void dfs(int u){
	dep[u]=dep[ffa[u][0]]+1;
	for(int i=1;i<=14;i++){
		ffa[u][i]=ffa[ffa[u][i-1]][i-1];
	}
	for(auto &v:G[u]){
		if(v==ffa[u][0])	continue;
		ffa[v][0]=u;
		dfs(v);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])	swap(u,v);
	for(int i=14;i>=0;i--){
		if(dep[ffa[u][i]]>=dep[v])	u=ffa[u][i];
	}
	for(int i=14;i>=0;i--){
		if(ffa[u][i]!=ffa[v][i])	u=ffa[u][i],v=ffa[v][i];
	}
	while(u!=v)	u=ffa[u][0],v=ffa[v][0];
	return u;
}
void dfs0(int i,int st){
	if(i>k){
		for(int j=1;j<=k;j++){
			fa[ch[j]]=ch[j];
		}
		for(int j=1;j<=k;j++){
			for(auto &v:G[ch[j]]){
				if(vis[v]){
					merge(v,ch[j]);
				}
			}
		}
		int cnt=0;
		for(int j=1;j<=k;j++){
			if(fa[ch[j]]==ch[j])	++cnt;
			if(cnt>2)	break;
		}
		if(cnt>2)	return;
		int cur=0;
		for(int i=1;i<=n;i++){
			int tmp=0x3f3f3f3f;
			for(int j=1;j<=k;j++){
				tmp=min(tmp,dep[i]+dep[ch[j]]-2*dep[llca[i][ch[j]]]);
			}
			cur=max(cur,tmp);
			if(cur>=ans)	break;
		}
		ans=min(ans,cur);
		return;
	}
	
	for(int j=st;j<=n-k+i;j++){
		vis[j]=true;
		ch[i]=j;
		dfs0(i+1,j+1);
		vis[j]=false;
	}
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			llca[i][i]=i;
			for(int j=1;j<i;j++){
				llca[i][j]=llca[j][i];
			}
			for(int j=i+1;j<=n;j++){
				llca[i][j]=lca(i,j);
			}
		}
		ans=0x3f3f3f3f;
		dfs0(1,1);
		cout << ans << '\n';
	}
	return 0;
}
/*
d(i)<=mid 
0 2
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


0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

6 5
1 2
2 5
4 5
5 3
3 6

9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
