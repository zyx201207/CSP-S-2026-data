#include<bits/stdc++.h>
using namespace std;
#define us unsigned
#define ll long long
#define pb emplace_back
#define il inline
#define For(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(a);i>=(b);--i)
inline ll read(){
	ll num=0;bool f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0' && c<='9')num=num*10+(c^48),c=getchar();
	return f?num:-num;
}
const ll N=1e6+5;
ll n,m,a[N],pre[N],ans;
#define sum(l,r) (pre[r]-pre[l-1])
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	For(i,1,n)a[i]=read();
	sort(a+1,a+1+n);
	For(i,1,n)pre[i]=pre[i-1]+a[i];
	For(i,1,n){
		ll l=1,r=i,res=1;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-sum(mid,i)<=m)res=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		if(res>ans)ans=res;
	}
	printf("%lld",ans);
	return 0;
} 
