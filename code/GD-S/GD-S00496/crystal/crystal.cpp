#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500007];
ll ans,sum[500007];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
	for(ll i=1;i<=n;i++){
		ll l=1,r=i,res=-1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid-1;
				res=mid; 
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}

