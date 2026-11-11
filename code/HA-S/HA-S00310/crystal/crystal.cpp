#include<bits/stdc++.h>
using namespace std;
int n,id;
long long m,s=LLONG_MAX,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i)
		for(int j=i-1;j;--j)
			b[i]+=a[i]-a[j];
	for(int i=n;i;--i){
		if(abs(b[i]-m)<s)
			s=abs(b[i]-m),id=i;
		if(b[i]==m){
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",id);
	return 0;
}
