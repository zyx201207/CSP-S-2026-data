#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define filename "and"
const int N=2*1e5+5;
int n,m,a[N],vis[N],ans=-1;
void dfs(int u,int now){
	if(u==m){
		ans=max(now,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(now*2<ans)continue;
		vis[i]=1;
		dfs(u+1,now&a[i]);
		vis[i]=0;
	}
	return;
}
signed main(){
	fastio;
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,(1<<22)-1);
	cout<<ans;
	return 0;
}
