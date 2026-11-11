#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5 +5;
ll n,m,a[N],ans,sum[N];
ll erfen(ll x){
	ll l=1,r=x,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(sum[x]-sum[mid-1])<=m)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ans=max(ans,i-erfen(i)+1);
	}
	cout<<ans;
	return 0;
}
