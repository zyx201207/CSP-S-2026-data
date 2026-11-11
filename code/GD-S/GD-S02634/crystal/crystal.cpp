#include<stdio.h>
#include<algorithm>
int n,l,r,mx;//窗口[l,r)
long long a[500005],c,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	std::sort(a,a+n);
	for(l=r=0;r<n;){
		c+=(a[r]-a[r-1])*(r-l);r++;
		while(c>m)c-=a[r]-a[l++];
		mx=(r-l)>mx?(r-l):mx;
	}printf("%d",mx);
	return 0;
}
