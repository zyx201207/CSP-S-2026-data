//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<unordered_set>
using namespace std;
constexpr const int N=1e6,inf=0x3f3f3f3f;
int n,k,father[N+1],depth[N+1],dfn[N+1],rnk[N+1];
vector<int>g[N+1];
struct ST{
	pair<int,int> st[N+1][__lg(N+1)+1];
	
	void build(int n){
		for(int i=1;i<=n;i++){
			st[i][0]={depth[rnk[i]],rnk[i]};
		}
		for(int i=1;(1<<i)<=n;i++){
			for(int x=1;x+(1<<i)-1<=n;x++){
				st[x][i]=min(st[x][i-1],st[x+(1<<i-1)][i-1]);
			}
		}
	}
	pair<int,int> query(int l,int r){
		int s=__lg(r-l+1);
		return min(st[l][s],st[r-(1<<s)+1][s]);
	}
}st;
int cnt;
void dfs0(int x,int fx){
	father[x]=fx;
	depth[x]=depth[fx]+1;
	dfn[x]=++cnt;
	rnk[dfn[x]]=x;
	for(int v:g[x]){
		if(v==fx){
			continue;
		}
		dfs0(v,x);
	}
}
int lca(int u,int v){
	if(u==v){
		return u;
	}
	if(dfn[u]>dfn[v]){
		swap(u,v);
	}
	return father[st.query(dfn[u]+1,dfn[v]).second];
}
void pre(){
	cnt=0;
	dfs0(1,0);
	st.build(n);
}
int dist(int u,int v){
	return depth[u]+depth[v]-2*depth[lca(u,v)];
}
void dfs1(int x,int fx,bool vis[],unordered_set<int>&s){
	vis[x]=true;
	for(int v:g[x]){
		if(v==fx||!s.count(v)){
			continue;
		}
		dfs1(v,x,vis,s);
	}
}
bool check(unordered_set<int>&s){
	static bool vis[N+1];
	for(int i:s){
		vis[i]=false;
	}
	int cnt=0;
	for(int x:s){
		if(!vis[x]){
			dfs1(x,0,vis,s);
			cnt++;
		}
	}
	return cnt<=2;
}
void dfs(int p,int &ans,unordered_set<int>&s){
	if(p>n){
		if(s.size()!=k){
			return;
		}
		if(!check(s)){
			return;
		}
		int Max=-inf;
		for(int i=1;i<=n;i++){
			int Min=inf;
			for(int j:s){
				Min=min(Min,dist(i,j));
			}
			Max=max(Max,Min);
		}
		ans=min(ans,Max);
		return;
	}
	dfs(p+1,ans,s);
	s.insert(p);
	dfs(p+1,ans,s);
	s.erase(p);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].resize(0);
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		pre();
		int ans=inf; 
		unordered_set<int>s;
		dfs(1,ans,s);
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}
/*
0 1
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
