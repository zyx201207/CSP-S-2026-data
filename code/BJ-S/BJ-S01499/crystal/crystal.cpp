#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
inline int read(){
	int x=0,f=1; char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}
const int N=5e5+5;
int n,a[N],k,s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),k=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	int mx=0;
	rep(i,1,n){
		int l=0,r=i;
		int ans=0;
		while(l<r){
			int mid=(l+r)>>1;
			if(mid*a[i]-(s[i]-s[i-mid])<=k) ans=mid,l=mid+1;
			else r=mid;
		}
		if((ans+1)*a[i]-(s[i]-s[i-ans-1])<=k) ans++;
		mx=max(mx,ans);
	}
	printf("%lld\n",mx);
	return 0;
}