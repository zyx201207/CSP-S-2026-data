#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<int> a(n+2),rt(m+1),ans(m+1);
	vector<vector<int>> g(n+2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		g[i].push_back(rt[a[i]]+1);
		g[rt[a[i]]+1].push_back(i);
	}
	stack<int> st; st.push(n+1);
	vector<int> order,par(n+2),sz(n+2);
	while(!st.empty()){
		int u=st.top(); st.pop();
		order.push_back(u);
		for(int v:g[u]){
			if(v==par[u]) continue;
			par[v]=u;
			st.push(v);
		}
	}
	for(int i=n;i>=1;i--){
		int u=order[i];
		sz[u]++,sz[par[u]]+=sz[u];
	}
	for(int i=1;i<=n;i++) ans[a[i]]+=sz[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
