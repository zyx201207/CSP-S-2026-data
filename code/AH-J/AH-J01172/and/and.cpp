#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	if(m==1){
		ll maxn=-114514;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	if(m==2){
		ll maxn=-114514;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ll ans=a[i];
				ans&=a[j];
				maxn=max(maxn,ans);
			}
		}
		cout<<maxn;
	}
	else{
		sort(a+1,a+1+n);
		ll ans=a[n];
		for(ll i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
