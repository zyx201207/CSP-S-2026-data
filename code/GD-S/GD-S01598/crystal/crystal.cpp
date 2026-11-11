#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=500005;
ll n,m,maxx=0;
ll a[N],ans[N];
int solve(){
	ll w=0,s=0;
	for(int i=1;i<=n;i++){
		w+=i*i;
		if(w<=m){
			s=i;
		}
		else{
			break;
		}
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag1=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flag1=0;
		}
	}
	if(flag1){
		cout<<solve()<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		ans[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		ll num=0;
		for(ll j=1;j<=n-i+1;j++){
			ll r=i+j-1;
			num+=ans[r]*(j-1);
			if(num<=m){
				maxx=max(maxx,j);
			}
			else{
				break;
			}
		}
	} 
	cout<<maxx<<endl;
	return 0;
} 
