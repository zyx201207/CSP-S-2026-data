#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10,inf=1e18+10;

ll n,m,a[N],sum[N];

inline bool check(ll mid){
	
	ll cnt=inf;
	for(int r=mid;r<=n;r++){
		
		ll l=r-mid+1,op=(l+r+1)/2;
		cnt=min(cnt,a[r]*mid-(sum[r]-sum[l-1]));
	}
	
	return cnt<=m;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	ll l=1,r=n,mid;
	while(l<=r){
		
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	
	cout<<r<<'\n';
	
	return 0;
}

/*
15:00 meow!
*/
