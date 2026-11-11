#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,flag,sum,ans;
ll a[N],p[N];
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>1){
			if(c[i]!=c[i-1])flag=1;
		}
		p[i]=p[i-1]+a[i];
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	ll sum;
	if(p[n]%2==0){
			sum=p[n]/2;
		}
		else{
			sum=p[n]/2+1;
		}
	for(ll i=1;i<=n;i++){
		if(p[i]<=sum){
			continue;
		}
		ll nm=p[i]-sum;
		ll mn=sum-nm;
		ll ok=lower_bound(p+1,p+n+1,mn)-p;
		if(c[ok]==c[i])continue;
		else{
			if(i==lower_bound(p+1,p+n+1,sum)-p){
				ans+=p[i]-sum;
			}
			else ans+=p[i]-p[i-1];
		} 
	}
	cout<<ans;
	return 0;
}
