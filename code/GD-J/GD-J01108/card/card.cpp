#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int n,m,a[N],c[N],hd[N];
vector<pair<int,int>>g[N];
int dfs(int x,int f){
	int sz=1;
	for(auto[y,z]:g[x])sz+=dfs(y,z);
	c[f]+=sz;return sz;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--)
		if(hd[a[i]])g[hd[a[i]]].push_back({i,0});
		else hd[a[i]]=i,g[i+1].push_back({i,a[i]});
	dfs(n+1,0);for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
