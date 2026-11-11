#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string ss;
const ll mmm=5e5+200;
const ll mod=1e9+7;
ll n,m;
ll a[mmm];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m; 
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll i=1;
	ll ans=1;
	while(m>0&&i<n){
		if(m>=abs(a[i+1]-a[i])*ans){
			i++;
			m-=(abs(a[i+1]-a[i])*ans);
			ans++;
		}else{
			break;
		}	 
	}
	cout<<ans;
	return 0;
}
