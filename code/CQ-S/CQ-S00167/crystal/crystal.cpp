#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long dp[500005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	dp[1]=0;
	for(int i=2;i<=n;i++) dp[i]=(a[i]-a[i-1])*(i-1)+dp[i-1];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dp[j]-dp[i]-(a[j]-a[i])*(i-1)<=m) ans=max(ans,j-i+1);
			else break;
		}
	}
	cout << ans;
	return 0;
}
