#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1){cout<<a[n];return 0;}
	if(m==n){
		ll sum=a[1]&a[2];
		for(ll i=3;i<=n;i++) sum=sum&a[i];
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
		return 0;
	}
	else cout<<a[n-m+1];
	return 0;
}
