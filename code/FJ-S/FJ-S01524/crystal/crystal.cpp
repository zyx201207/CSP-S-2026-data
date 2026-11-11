#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N];
ll cha[N],s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	ll len=n;
	if(a[1]>=0){
		while(len--){
			ll l=1,r=len+l-1;
			ll x=a[r]*len-(s[r]-s[l-1]);
			if(x<=m){
				cout<<len;
				return 0;
			}
		}
	}
	while(len--){
		for(ll l=1;l<=n-len+1;l++){
			ll r=len+l-1;
			ll x=a[r]*len-(s[r]-s[l-1]);
			if(x<=m){
				cout<<len;
				return 0;
			}
		}
	}
	return 0;
}