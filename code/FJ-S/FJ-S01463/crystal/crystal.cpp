#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],l=1e18,r=-1e18,d[N],ans;
long long read(){
	long long k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+c-'0';
	return k*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	for(int i=1,j=1;i<=n;i++){
		if(a[i]*i-d[i]<=m) ans=max(ans,1ll*i);
		else {
			while(a[i]*(i-j)-(d[i]-d[j])>m&&j<=i) j++;
			ans=max(ans,1ll*(i-j));
		}
	}
	printf("%lld",ans);
	return 0;
}
