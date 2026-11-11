#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,m;
ll a[N],b[N];
bool ok=1;
bool check(ll x){
	ll res=0;
	for(int i=x;i<=n;i++){
		res=0;
		for(int j=1;j<x;j++){
			res+=(x-j)*(b[i-j+1]);
		}
		if(res<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i>1) ok=0;
	}
	if(ok){
		int ans=1;
		while(m>0){
			m-=ans*b[1];
			ans++;
		}
		if(m<0) ans--;
		cout<<ans<<endl;
		return 0;
	}
	ll l=1,r=n;
	while(l+1<r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}
