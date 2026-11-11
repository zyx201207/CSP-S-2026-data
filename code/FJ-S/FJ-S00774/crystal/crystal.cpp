#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}//(x-1)*a[i]-(b[i-1]-b[i-x])
int a[500005],n,m,b[500005];
int check(int x){
	int minn=INT_MAX;
	for(int i=x;i<=n;i++) minn=min(minn,(x-1)*a[i]-(b[i-1]-b[i-x]));
	return minn;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)>m) r=mid-1;
		else l=mid+1;
	}
	write(r);
	return 0;
}

