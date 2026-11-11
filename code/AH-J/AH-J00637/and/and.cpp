#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[400000];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ll sum=a[1];
		for(ll i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		ll maxn=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	if(m==n-1){
		ll maxn=0;
		sort(a+1,a+1+n,cmp);
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
