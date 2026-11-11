#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,b[200005],x;
inline void sss(long long x,long long t){
	if(x==n+1){
		if(t!=m)return;
		long long u=0;
		for(int i=1;i<=n;i++){
			if(b[i]==1)
				if(u==0)
					u=a[i];
				else
					u&=a[i];
		}
		ans=max(ans,u);
		return;
	}
	if(t<m)
		b[x]=1,sss(x+1,t+1);
	b[x]=0,sss(x+1,t);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=20){
		sss(1,0);
		printf("%lld",ans);
		return 0;
	}
	x=1;
	for(long long i=2;i<=n;i++)
		if(a[i]!=a[i-1])x=0;
	if(x==1){
		printf("%lld",a[1]);
		return 0;
	}
	x=1;
	for(int i=1;i<=n;i++)
		if(a[i]!=(1<<i)-1)
			x=0;
	if(x==1){
		printf("%lld",a[n-m+1]);
		return 0;
	}
	x=0;
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					x=max(x,a[i]&a[j]);
		printf("%lld",x);
		return 0;
	}
	x=0;
	if(n==m){
		x=a[1];
		for(int i=2;i<=n;i++)
			x=x&a[i];
		printf("%lld",x);
	}
    return 0;
}
