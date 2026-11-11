#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
int vis[M],a[M],n,m,ans[M];
deque<int>dp[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]]){
			dp[i]=dp[vis[a[i]]];
			vis[a[i]]=i;
		}
		else{
			dp[i]=dp[i+1];
			dp[i].push_front(a[i]);
			vis[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<dp[i].size();j++){
			ans[dp[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

