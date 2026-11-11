#include<stdio.h>
#include<algorithm>
#define N 500001
#define ll long long
int n,m,l,r,mid;
ll a[N],b[N];
bool chk(int x){
	ll s=0;
	for(int i=2;i<=x;++i)s+=b[i]*(i-1);
	if(s<=m)return 1;
	for(int i=x+1;i<=n;++i){
		s=s-a[i-1]+a[i-x]+b[i]*(x-1);
		if(s<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=a[i]-a[i-1];
	l=1,r=n+1;
	while(l+1<r)chk(mid=l+r>>1)?(l=mid):(r=mid);
	printf("%lld",l);
	return 0;
}
