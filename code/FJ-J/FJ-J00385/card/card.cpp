#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],b[300005],siz[500005];
vector<int> v[500005];
void dfs(int x){
	siz[x]=1;
	for(int i=0;i<v[x].size();i++){
		dfs(v[x][i]);
		siz[x]+=siz[v[x][i]];
	}
	ans[a[x]]+=siz[x];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0)b[a[i]]=i;
		v[b[a[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
