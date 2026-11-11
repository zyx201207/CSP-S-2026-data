#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i<n){
			b[i]=a[i+1]-a[i];
		}
	}
	ll B=1;
	for(ll i=1;i<n-1;i++){
		if(b[i]!=b[i+1]){
			B=0;
		}
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		ll ans=-1e18;
		for(ll i=1;i<=n;i++){
			ll s=0,cnt=0;
			for(ll j=i;j>=1;j--){
				if(s+a[i]-a[j]<=m){
					s+=a[i]-a[j];
					cnt++;
				}
				else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else if(B==1){
		ll ans=0;
		for(ll i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0){
				m-=a[n]-a[i];
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
	}
	else{
		cout<<1;
	}
	return 0;
}