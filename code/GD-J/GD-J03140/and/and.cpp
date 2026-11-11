#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200009],dp[200009],maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
    	maxn=max(a[i],maxn);
	}
	for(ll i=1;i<=n;i++){
		dp[0]=maxn;
		for(int j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
