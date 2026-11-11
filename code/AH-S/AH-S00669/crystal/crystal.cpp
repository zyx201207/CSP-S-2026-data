#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+10;
ll n,m;
ll a[N],cha[N];
ll ans;
ll c[N];
ll lowbit(ll x){
	return x&-x;
}
void add(ll x,ll k){
	while(x<=n){
		c[x]+=k;
		x+=lowbit(x);
	}
	return ;
}
ll query(ll x){
	ll res=0;
	while(x){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
ll sum(ll ql,ll qr){
	return query(qr)-query(ql-1);
}
bool check(ll t){
	ll pre=0;
	for(ll i=2;i<=t;i++)
		pre+=(i-1)*cha[i];
	if (pre<=m)	return true;
	for(ll i=3;i<=n-t+2;i++){
		pre+=cha[i+t-2]*(t-1);
		pre-=sum(i-1,i+t-3);
		if (pre<=m)	return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		add(i,cha[i]);
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
		if (check(mid)){
			l=mid+1;
			ans=mid;
		}else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
