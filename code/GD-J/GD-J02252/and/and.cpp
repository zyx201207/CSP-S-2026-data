#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
int ans=0;
void dfs(int i,int step,int sum){
	if (step==m){
		ans=max(ans,sum);
		return ;
	}
	for (int j=i+1;j<=n;j++){
		dfs(j,step+1,sum&a[j]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}
