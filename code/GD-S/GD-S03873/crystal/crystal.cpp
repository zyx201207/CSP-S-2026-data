#include<bits/stdc++.h>
using namespace std;using ll=long long;using ull=unsigned long long;

constexpr int N=5e5+9;
ll a[N],ps[N],n,m,ans;

inline ll sum(int l,int r){
	return ps[r]-ps[l-1];
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	partial_sum(a+1,a+1+n,ps+1);
	for(ll i=1;i<=n;i++){ //check each one as last
		if(m>=a[i]*i-sum(1,i)){
			ans=max(ans,i);
			continue;
		}
		ll res=i; //left pointer
		for(ll l=1,r=i,mid;l<=r;){ //minimize
			mid=l+(r-l)/2;
			if(m>=a[i]*(i-mid+1)-sum(mid,i)){
				res=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}

/*
5 5
1 2 4 8 9

5 8 
-3 -1 2 2 7
*/
