#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],ans[300005];
int dp[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],lst[a[i]]=i,dp[i]=1;
	for(int i=1;i<=n;i++){
		if(lst[a[i]]==i) ans[a[i]]+=dp[i],dp[i+1]+=dp[i];
		else dp[lst[a[i]]]+=dp[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
