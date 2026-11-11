#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll r=0,w=1;char c=getchar();
	while(c<'0'||c>'9') w=(c=='-')?(-1):(w),c=getchar();
	while(c>='0'&&c<='9') r=(r<<3)+(r<<1)+(c^48),c=getchar();
	return r*w;
}const int N=5e5+5;
ll n,m,a[N],pre[N],ans;
void Meow(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid;
		while(l<=r){
			mid=((r-l)>>1)+l;
			if(a[i]*mid-pre[i]+pre[i-mid]<=m) l=mid+1;
			else r=mid-1;
		}ans=max(ans,r);
	}printf("%lld",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	while(t--) Meow();
	return 0;
}
