#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
int a[500005];
int f[300005];
void dfs(int u){
	if(u==n+1)return ;
	ans[a[u]]++;
	dfs(f[a[u]]+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);   cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}

