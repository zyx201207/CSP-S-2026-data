#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],dp[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	dp[1]=maxx;
	for(ll i=1;i<=n;i++){
		if(a[i]!=maxx){
			for(ll j=m;j>=1;j--){
				dp[j]=max(dp[j],(dp[j-1]&a[i]));
			}
		}
	}
	cout<<dp[m];
	return 0;
}
