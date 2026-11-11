#include <stdio.h>
#include <algorithm>
#define MAX(a,b) ((a)>(b)?(a):(b))
const int N=5e5+100;
int n,len,ans;
long long m,a[N],use;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		use+=(a[i]-a[i-1])*len;
		len++;
		while(use>m){
			use-=a[i]-a[i-len+1];
			len--;
		}
		ans=MAX(ans,len);
	}
	printf("%d",ans);
	return 0;
}
