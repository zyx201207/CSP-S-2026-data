#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[30];
inline void dfs(int u,int v,int sum){
	if(v>m) return ;
	if(sum<ans) return ;
	if(u==n+1){
		if(v==m) ans=sum;
		return ;
	}
	dfs(u+1,v+1,(sum&a[u]));
	dfs(u+1,v  , sum      );
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,4294967295);
	cout<<ans;
	return 0;
}