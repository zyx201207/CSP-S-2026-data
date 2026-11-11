#include <bits/stdc++.h>

using namespace std;

#define N 500010
#define ll long long

ll n,m,a[N];
ll num[N],dp[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fl1=true,fl2=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;num[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i) fl1=false;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fl2=false;
	}
	if(fl1){
		ll id=1;
		while(m>=0){
			m-=id;
			id++;
		}
		cout<<id-1;return 0;
	}
	if(fl2){
		ll q=a[2]-a[1],id=1;
		while(m>=0){
			m-=id*q;
			id++;
		}
		cout<<id-1;return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ll w=dp[i-j]*a[i]-num[i-j];
			if(w<=m){
				if(dp[i]<dp[i-j]+1){
					dp[i]=dp[i-j]+1;
					num[i]=a[i]+num[i-j];
				}
			}
		}
	}
	ll maxn=-1;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
