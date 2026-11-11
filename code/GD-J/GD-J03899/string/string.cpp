#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+9;
ll n,idx;
char a[N],b[N];
ll dp[4005][4005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		ll x;
		char y;
		cin >>x>>y;
		while(x--){
			a[++idx]=y;
		}
	}
	for(int i=1;i<=idx;i++){
		b[i]=a[idx-i+1];
	}
	for(int i=1;i<=idx;i++){
		for(int j=1;j<=idx;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
		}
	}
	ll ans=max(idx-dp[idx][idx]-1,0LL);
	cout<<ans;
	return 0;
} 
