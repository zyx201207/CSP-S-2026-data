#include<bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll c,t,n,d,ans;
ll le[N],ri[N];
ll a[N],b[N],o[N];
//ll le[N],ri[N];
//deque<pair<ll,ll> >q;
//a原数组b一个点所能跳最远的点下标o一个点所对应的特别点 
//ll tr[N];
//ll lb(ll x){return x&(-x);}
//void add(ll x,ll y){
//	for(ll i=x;i<=n;i+=lb(i))tr[i]+=y;
//}
//ll sum(ll x){
//	ll res=0;
//	for(ll i=x;i;i-=lb(i))res+=tr[i];
//	return res;
//}
ll yuan(ll p){//p<n
	ll l=p+1,r=n,an=p+1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(a[mid]-a[p]==d)return mid;
		if(a[mid]-a[p]<d)l=mid+1,an=mid;
		else r=mid-1;
	}
	return an;
}
signed main(){//没机会了 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		ll pp=1;
		cin>>n>>d;
		for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(ll i=1;i<n;++i)b[i]=yuan(a[i]);
		for(ll i=1;i<n;++i){
			if(a[b[b[i]]]-a[b[i]-1]<=d&&a[b[b[i]]]-a[b[i]-2]>d)++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
