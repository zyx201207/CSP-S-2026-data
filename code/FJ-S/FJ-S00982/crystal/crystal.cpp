#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll MAXN=5e5+5;
ll n,m,a[MAXN],ans,q[MAXN];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1; i<=n; i++) {
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ll l=1,now=m;
	q[1]=a[1];
	ans=1;
	for(ll r=2; r<=n; ++r) {
		q[r]=a[r];
		now-=(a[r]-a[r-1])*(r-l);
		while(now<0){
			now+=(q[r]-q[l]);
			++l;
		}
		ll siz=r-l+1;
		ans=max(ans,siz);
	}
	printf("%lld",ans);
	return 0;
}
