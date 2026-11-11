#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,a[600010],dp[600010],s;
ll sum=0,t=1,ans=1,sf=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		dp[i]=a[i+1]-a[i];
		if(dp[i]==1)sf++;
		sum=sum+dp[i]*i;
		ans++;
		if(sf>=m){
			cout<<m+1;return 0;
		}
		while(sum>m){
			for(int j=t;j<=i;j++)sum=sum-dp[j];
			t++;
			ans--;
		}
		s=max(s,ans);
	}
	cout<<s;
	return 0;
}
