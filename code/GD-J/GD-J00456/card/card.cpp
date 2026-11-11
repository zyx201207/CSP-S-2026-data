#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],b[500005],d[500005],g[500005];
vector<int> a[500005];
void dfs(int u){
	d[u]++;
	for(auto v:a[u])
	{
		dfs(v);d[u]+=d[v];
	}
	g[b[u]]+=d[u];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];c[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[b[i]]==i)a[i+1].push_back(i);
		else a[c[b[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<m;i++)cout<<g[i]<<" ";
	cout<<g[m];
	return 0;
}
