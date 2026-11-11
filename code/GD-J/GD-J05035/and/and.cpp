#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,ans,a[N],dp[N];
void dfs(int u,int r,int sum){
	if(u>n){
		if(r==m) ans=max(ans,sum);
		return;
	}
	if((n-u)<(m-r)) return;
	dfs(u+1,r+1,(r==0?a[u+1]:sum&a[u+1]));
	dfs(u+1,r,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	dfs(1,1,a[1]);
	cout<<ans;
	return 0;
}
