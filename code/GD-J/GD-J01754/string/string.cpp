#include <bits/stdc++.h>
typedef long long ll;
struct node {
	ll s,f;
	char c;
}dt[200010];
ll n,sz,ans;
std::pair<ll,ll> cross(ll lb,ll rb,ll pos) {
	ll pl=std::max(lb,dt[pos].s),pr=std::min(rb,dt[pos].f);
	ll ic=pr-pl+1,sp=0;
	if(dt[pos].s==pl&&pr<=dt[pos].f) sp=1;
	if(dt[pos].s<pl&&pr==dt[pos].f) sp=0;
	return {ic,sp};
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin>>n;
	for(ll i=1,ln;i<=n;i++) {
		std::cin>>ln>>dt[i].c;
		dt[i].s=sz+1;
		dt[i].f=sz+ln;
		sz=dt[i].f;
	}
	ll len=sz/2,o=n;
	for(ll i=1;dt[i].s<=len;i++) {
		ll l=dt[i].s,r=std::min(dt[i].f,len);
		ll tl=sz+1-r,tr=sz+1-l;
		while(1) {
			std::pair<ll,ll> tmp=cross(tl,tr,o);
			ll ic=tmp.first,sp=tmp.second;
			if(dt[i].c!=dt[o].c) ans+=ic;
			if(sp==0) break;
			o-=sp;
		}
	}
	std::cout<<ans;
	return 0;
}
