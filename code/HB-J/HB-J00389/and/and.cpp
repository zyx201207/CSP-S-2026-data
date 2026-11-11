#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,c[200005],tre[800005],ans=0;
void pushup(ll p){
	tre[p]=tre[p*2]&tre[p*2+1];
}
void build(ll p,ll l,ll r){
	if(l==r){
		tre[p]=c[l-1];
		return;
	}
	build(p*2,l,(l+r)/2);
	build(p*2+1,(l+r)/2+1,r);
	pushup(p);
}
ll query(ll p,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&r<=qr) return tre[p];
	ll mid=(l+r)/2;
	ll ret=1073741823;
	if(ql<=mid) ret&=query(p*2,l,mid,ql,qr);
	if(mid+1<=qr) ret&=query(p*2+1,mid+1,r,ql,qr);
	return ret;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;++i){
		cin>>c[i];
	}
	if(n<=20){
		for(ll i=0;i<(1LL<<n);++i){
			ll val=1073741823;
			ll cnt=0;
			for(ll j=0;j<n;++j){
				if((i>>j)&1){
					++cnt;
					val=val&c[j];
				}
			}
			if(cnt==m) ans=max(ans,val);
		}
	}
	else if(n<=2000&&m==1) ans=*max_element(c,c+n);
	else if(n<=2000&&m==n){
		ans=1073741823;
		for(ll i=0;i<n;++i){
			ans&=c[i];
		}
	}
	else if(n<=2000&&m==2){
		for(ll i=0;i<n;++i){
			for(ll j=i+1;j<n;++j){
				ans=max(ans,c[i]&c[j]);
			}
		}
	}
	else{
		sort(c,c+n);
		build(1,1,n);
		for(ll i=1;i<=n-m+1;++i){
			ans=max(ans,query(1,1,n,i,i+m-1));
		}
	}
	cout<<ans;
	return 0;
}
