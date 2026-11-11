#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,num,x;
ll a[500009],f[500009];
bool b,b1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		f[i]=f[i-1]+a[i];
		if(a[i]!=i) b=1;
		if(i==2) x=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=x) b1=1; 
	}
	if(!b){
		ll num=0;
		for(ll i=n-1;i>=1;i--){
			num+=(n-i);
			if(num>m){
				cout<<n-i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(!b1){
		for(ll i=n-1;i>=1;i--){
			num+=(a[n]-a[i]);
			if(num>m){
				cout<<n-i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		num+=abs(a[n]-a[i]);
	}
	if(num<=m){
		cout<<n;
		return 0;
	}
	for(ll i=n-1;i>=2;i--){
		ll ans=a[i]*(i-1)-f[i-1];
		if(ans<=m){
			cout<<i;
			return 0;
		}
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
