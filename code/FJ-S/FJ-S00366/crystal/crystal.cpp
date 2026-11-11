#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=5e5+10;

ll n,m;
ll a[N];
ll sum[N];
ll ans=0;

map<ll,ll>mp;

bool cmp(ll t1,ll t2) {
	return t1<t2;
}

ll check(ll ids) {
	ll l=1,r=ids-1;
	while(l<r) {
//		cout<<1;
		if(r-l==1) {
			ll temp=sum[ids-1]-sum[l-1];
			ll cha=ids-l;
			ll num=cha*a[ids]-temp;
//			cout<<"*"<<num<<"*"<<l<<endl;
			if(num<=m)r=l;
			else l=r;
			break;
		}
		ll mid=l+(r-l+1)/2;
		ll temp=sum[ids-1]-sum[mid-1];
		ll cha=ids-mid;
		ll num=cha*a[ids]-temp;
//		cout<<l<<" "<<r<<" "<<mid<<" "<<num<<endl;
		if(num>m) {
			l=mid+1;
		} else {
			r=mid;
		}
	}
	return l;
}
void cs(ll id) {
	cout<<check(id)<<" "<<id<<endl;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
//	m=0;
	for(ll i=1; i<=n; i++)cin>>a[i],mp[a[i]]++;
	sort(a+1,a+n+1,cmp);
	for(ll i=1; i<=n; i++) {
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll k=check(i);
		ans=max(ans,i-k+1);
//		if(i-k+1==315276)break;
//		cout<<k<<" "<<i<<endl;

	}
//	cs(428130);
//	cs(428133);
//	cout<<a[428132]<<endl;
//	cout<<a[428133];
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

8 2
1 3 3 3 5 5 5 5
*/

