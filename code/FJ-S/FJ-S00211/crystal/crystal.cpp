#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st stack
#define qu queue
#define qp priority_queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 500005
ll n=0,m=0;
ll a[N]={0};
ll aaa(ll a,ll b,ll c){
	if(a/b>=c){
		return 1;
	}else{
		return 0;
	}
} 
int main(){
	qwq;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	ll b=0;
	if(n<=5000){
		ll maxx=0;
		for(ll i=1;i<=n;i++){
			ll ans=1;
			b=m;
			for(ll j=i+1;j<=n;j++){
				if(b>=(a[j]-a[j-1])*(j-1)){
					ans++;
					b-=(a[j]-a[j-1])*(j-1);
				}else{
					break;
				}
			}
			maxx=max(maxx,ans);
		}
		cout<<maxx<<endl;
	}else{
		ll ans=1;
		for(ll i=2;i<=n;i++){
			if(m>=(a[i]-a[i-1])*(i-1)){
				ans++;
				m-=(a[i]-a[i-1])*(i-1);
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
