#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],nxt[500005],lst[300005],dp[500005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ok,w;
	ok = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]]){
			nxt[lst[a[i]]] = i;
		}
		lst[a[i]] = i;
		dp[i] = 1;
	}
	for(int i = 1;i<=n;i++){
		if(!nxt[i-1]){
			dp[i] = dp[i]+dp[i-1];
		}
		dp[nxt[i]] = dp[nxt[i]]+dp[i];
	}
	for(int i = 1;i<=n;i++){
		if(!nxt[i]){
			ans[a[i]] = dp[i];
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}

