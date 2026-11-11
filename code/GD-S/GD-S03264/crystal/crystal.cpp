#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,ar[N];
map<ll,ll> mp;
bool check(ll x){
	ll sum=0,mi;
	for(int i=1;i<=x;i++){
		sum+=ar[x]-ar[i];
	}
	if(sum<=m) return 1;
	for(int i=2;i+x-1<=n;i++){
		sum-=(ar[i+x-2]-ar[i-1]);
		sum+=(x-1)*(ar[i+x-1]-ar[i+x-2]);
		if(sum<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	//	mp[ar[i]]++;
	}
	sort(ar+1,ar+n+1);
//	for(int i=1;i<=n;i++) cout<<ar[i]<<" ";
	ll l=0;
	ll r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
//	check(5);
/*
5 5
1 2 4 8 9


*/

	return 0;
}

