#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll arr[100005];
ll dp[100005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll v=0;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]==0)v++;
	}
	
	sort(arr,arr+n);
	dp[0]=0x7ffffffff;
	
	for(int i=1;i<=m;i++){
		if (i==1)dp[i]=arr[i+v];
		else dp[i]=dp[i-1]&arr[i+v];
	}
	for(ll i=m+1+v;i<=n;i++){
		for(ll j=m;j>=1;j--){
			dp[j]=max(dp[j],dp[j-1]&arr[i]);
		}
	}
	cout<<dp[m];
	return 0;
}

