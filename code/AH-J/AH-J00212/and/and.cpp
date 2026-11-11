#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,dp[200010],dp1[200010];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll a[200010],s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		if(i==1) s=a[1];
		s=(s&a[i]);
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		cout<<s;
		return 0;
	}
	for(ll i=1;i<=m;i++){
		if(i==1) s=a[1];
		s=(s&a[i]);
	}
	dp[1]=a[1];
	dp1[1]=1;
	dp[2]=(a[1]&a[2]);
	dp1[2]=2;
	ll maxn=0;
	for(int i=3;i<=n;i++){
		if((dp[i-1]&a[i])>=(dp[i-2]&a[i])){
			if((a[i]&a[i-1])>(dp[i-1]&a[i])){
				dp[i]=(a[i]&a[i-1]);
				dp1[i]=2;
			}else{
			dp[i]=(dp[i-1]&a[i]);
			dp1[i]=dp1[i-1]+1;
			}
		}else{ 
			dp[i]=(dp[i-2]&a[i]);
			dp1[i]=dp1[i-2]+1;
			
		}
		if(dp1[i]==m){
				maxn=max(maxn,dp[i]);
			}
	}
	cout<<max(maxn,s);
	return 0;
}
