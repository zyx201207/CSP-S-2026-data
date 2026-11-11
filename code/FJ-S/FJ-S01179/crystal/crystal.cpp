#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=5e5+5;

ll n,m,a[N],sum[N],ans;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	n=read(),m=read();
	for(ll i=1;i<=n;++i)a[i]=read();sort(a+1,a+1+n);
	for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	ll l=1;for(ll r=1;r<=n;++r){
		while(l<=r&&(r-l+1)*a[r]-(sum[r]-sum[l-1])>m)++l;
		ans=max(ans,r-l+1);
	}printf("%lld\n",ans);
	return 0;
}

// long long 
