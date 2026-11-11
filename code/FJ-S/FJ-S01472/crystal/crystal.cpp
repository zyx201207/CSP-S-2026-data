#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn=5e5+10;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res*f; 
}

ll owo[maxn],pre[maxn],n,m;
inline bool check(ll x,ll i){
	return (i-x+1)*owo[i]-(pre[i]-pre[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	memset(owo,0,sizeof(owo));
	memset(pre,0,sizeof(pre));
	
	n=read(),m=read();
	for (ll i=1;i<=n;++i)
		owo[i]=read();
	
	sort(owo+1,owo+n+1);
	
	for (ll i=1;i<=n;++i)
		pre[i]=pre[i-1]+owo[i];
	
	ll ans=0;
	for (ll i=1;i<=n;++i){
		ll l=1,r=i,pos=i;
		while (l<=r){
			ll mid=(l+r)/2;
			if (check(mid,i)) pos=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	printf("%lld ",ans);
} 
