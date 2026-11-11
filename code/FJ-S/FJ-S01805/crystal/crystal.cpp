#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],l,r,mid,ans;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline bool check(ll mid){
	ll sum=0;
	for(int i=1;i<=mid;i++) sum+=a[i];
	if(mid*a[mid]-sum<=m) return 1;
	for(int i=mid+1;i<=n;i++){
		sum+=a[i];
		sum-=a[i-mid];
		if(mid*a[i]-sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	l=0,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
