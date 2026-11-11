#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MX=5e5+1,MX2=3e5+1;
int n,m,a[MX],fa[MX],b[MX2],sz[MX];
vector<int> son[MX];
void dfs(int u){
	sz[u]=1;
	for(int v:son[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<n;++i){
		if(b[a[i]]!=i){
			fa[i]=b[a[i]];
		}else{
			fa[i]=i+1;
		}
		son[fa[i]].push_back(i);
	}
	dfs(n);
	for(int i=1;i<=m;++i){
		cout<<sz[b[i]]<<' ';
	}
	return 0;
}

