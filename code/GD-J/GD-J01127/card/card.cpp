#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],dp[300005],f[300005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		f[a[i]]++;
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[a[i]]++;
		if(f[a[i-1]]==0) dp[a[i]]+=dp[a[i-1]];
		f[a[i]]--;
	}
	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
	return 0; 
}
