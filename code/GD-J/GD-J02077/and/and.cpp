#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
ll n,m,ans,a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll mx=0;
		for(ll i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		ll mx=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		ll cnt=a[1];
		for(ll i=2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==n-1){
		ll mn=a[1],cnt=a[1];
		for(ll i=2;i<=n;i++){
			mn=min(mn,a[i]); 
		}
		for(ll i=1;i<=n;i++){
			if(a[i]==mn){
				mn=-1;
			}else cnt&=a[i];
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
