#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll maxn=-1,minn=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=-1;
	ll l=minn,r=maxn;
	while(l<r){
		ll mid=(r-l)/2+l;
		ll sum=0;
		ll nmx=0;
		for(ll j=1;j<=n;j++){
			if(mid-a[j]>=0){
				sum=sum+mid-a[j];		
				nmx++;			
			}
		}
		if(sum>m){
			r=mid;
			nmx--;
		}else{
			l=mid+1;
		}
		ans=max(nmx,ans);
	}
	cout<<ans;
	return 0;
}
