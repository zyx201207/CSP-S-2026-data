#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],i,j,sum=0,c[500005],dp[500005],ans;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)c[i]=a[i]-a[i-1];
	for(i=2;i<=n;i++){
		if(sum+c[i]*(i-1)>m)break;
		sum+=c[i]*(i-1);
	}dp[1]=i-1;
	for(int i=2;i<=n;i++){
		sum-=a[dp[i-1]]-a[i-1];
		for(j=dp[i-1]+1;j<=n;j++){
			if(sum+c[j]*(j-i)>m)break;
			sum+=c[j]*(j-i);
		}dp[i]=j-1;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]-i+1);
	}cout<<ans;
	return 0;
}
