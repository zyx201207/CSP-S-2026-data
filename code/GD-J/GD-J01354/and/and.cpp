#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
int n,m,a[N],dp[N],ans;
void dfs(int x,int y,int sum){
	if(x==n+1){
		if(y==m)ans=max(ans,sum);
		return;
	}
	dfs(x+1,y,sum);
	if(y+1<=m){
		if(!y){
			dfs(x+1,y+1,a[x]);
		}
		dfs(x+1,y+1,(sum&a[x]));
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

