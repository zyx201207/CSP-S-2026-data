#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500005,M=1e18+18,maxa=1e12+12;
ll n,m;
ll a[N];
ll sum[N];//1-range
ll ans=0;
ll find(ll from){
	ll l=from,r=n;
	while(l<r){
		ll mid=(l+1+r)/2;
		if(a[mid]*(mid-from+1)-sum[mid]+sum[from-1]>m) r=mid-1;
		else l=mid;//<<l<<" "<<r<<" "<<a[mid]*(mid-from+1)-sum[mid]+sum[from-1]<<endl;
	}//<<l<<endl;
	return l-from+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);sum[1]=a[1];
	for(ll i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		ans=max(ans,find(i));
	}cout<<ans;//¶þ·Ö´ð°¸
	//O(nlogn)
	fclose(stdin);
	fclose(stdout);
	//lost text correctly pass!!!
	return 0;
	 
}
