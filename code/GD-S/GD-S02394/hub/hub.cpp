#include<iostream>
#include<unordered_set> 
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=1e6+100;
int T,ans; 
int n,k,fa[MAXN][30],dep[MAXN],vis[MAXN];
unordered_set<int> se;
vector<int> e[MAXN];
int lca(int a,int b){
	if(dep[b]>dep[a])
		swap(a,b);
	for(int i=25;i>=0;i--)
		if(dep[fa[a][i]]>=dep[b])
			a=fa[a][i];
	if(a==b)
		return a;
	for(int i=25;i>=0;i--)
		if(fa[a][i]!=fa[b][i])
			a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
void dfs1(int u,int f,int d){
	fa[u][0]=f;
	dep[u]=d;
	for(int v:e[u])
		if(v!=f)
			dfs1(v,u,d+1);
}
void ck(int u,int f,int d){
	vis[u]+=d;
	for(int v:e[u])
		if(v!=f&&se.count(v))
			ck(v,u,d);
}
void gs(int s,int d){
	if(d>k){
		for(int i=1;i<=n;i++)
			vis[i]=0;
		ck((*se.begin()),0,1);
		for(int i:se)
			if(!vis[i]){
				ck(i,0,2);
				break;
			}
		for(int i:se)
			if(vis[i]==0||vis[i]==3)
				return;
		int res=0;
		for(int i=1;i<=n;i++){
			if(se.count(i)) continue;
			int res1=(1<<30);
			for(int j:se)
				res1=min(res1,dep[i]+dep[j]-2*dep[lca(i,j)]);
			res=max(res,res1);
			//cout<<'\n';
		}
		//cout<<'\n';
		ans=min(ans,res);
//		for(int i=1;i<=k;i++)
//			cout<<se[i]<<' ';
//		cout<<'\n';
		return;
	}
	for(int i=s;i<=n;i++){
		se.insert(i);
		gs(i+1,d+1);
		se.erase(i);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>T;
	while(T--){
		cin>>n>>k;
		ans=(1<<30);
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=2,u,v;i<=n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0,1);
		for(int j=1;j<=25;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		gs(1,1);
		cout<<ans<<'\n';
	}
	return 0;
} 
