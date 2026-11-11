//T1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e5+5;

ll n,m,a[maxn],s[maxn];

bool chk(ll mid){
	for(ll i=mid;i<=n;i++){
		__int128 sum=(__int128)(s[i]-s[i-mid]);
		__int128 tot=(__int128)(mid*a[i]);
		if(tot>0){
			if(sum>=tot-(__int128)m){
				return 1;
			}
		}else{
			if(sum+(__int128)m>=tot){
				return 1;
			}
		}
	}
	return 0;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(chk(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
/*
-446 4286 -47564 -6068 67930 -70811 67720 
-22319 -54509 -64628 -11473 67757 -20562 
-89766 -31128 -68081 -94743 -83304 -9530 
89120 21083 73613 8066 -36057
*/
