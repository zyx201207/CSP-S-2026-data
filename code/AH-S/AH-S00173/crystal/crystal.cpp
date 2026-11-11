#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],m,n,sum[500005];

ll read(){
	ll an=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		an=an*10+c-'0';
		c=getchar();
	}
	return an*f;
}

bool check(ll x){
	for(ll i=x;i<=n;i++){
		ll w=(x-1)*a[i]-(sum[i-1]-sum[i-x]);
		if(w<=m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=500000,ans=1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
