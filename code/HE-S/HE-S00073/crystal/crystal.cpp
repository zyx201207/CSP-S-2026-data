#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=10000){
		for(ll i=1;i<=n;i++){
			ll x=1,t=m;
			for(ll j=i-1;j>=1;j--){
				if(a[i]-a[j]>t){
					break;
				}else{
					t-=a[i]-a[j];
					x++;
				}
			}
			ans=max(ans,x);
		}
		cout<<ans;
	}else{
		ll g=a[2]-a[1]; 
		for(ll i=1;i<=n;i++){
			if(m<g*i){
				cout<<ans;
				return 0;
			}
			m-=g*i;
			ans++;
		}
		cout<<n;
	}
	return 0;
} 
