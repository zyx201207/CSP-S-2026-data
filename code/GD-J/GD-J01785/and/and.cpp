#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],l,r,ans,mx,pw[50];
bool check(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		ll y=(a[i]&x);
		if(y==x) sum++;
		if(sum>=m) return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=31;i++) pw[i]=pw[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];mx=max(mx,a[i]);
	}
	ans=0;
	for(int i=31;i>=0;i--){
		ll d=ans+pw[i];
		if(check(d)){
			ans+=pw[i];
		}
	}
	cout<<ans;
	return 0;
}

