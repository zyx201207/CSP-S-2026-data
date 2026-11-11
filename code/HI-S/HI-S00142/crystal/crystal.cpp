#include<algorithm>
#include<cstdio>
#define LL long long
#define MXN 500005
using namespace std;
LL a[MXN],c,d[MXN],m;
int A,l,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		c+=(i-l-1)*d[i];
		while(l<=i&&c>m)c-=a[i]-a[++l];
		A=max(A,i-l);
	}
	printf("%d",A);
	return 0;
}
