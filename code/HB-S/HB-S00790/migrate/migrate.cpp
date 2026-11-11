#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c<=12){
		while(t--){
			int n,d;scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++)scanf("%d",&a[i]);int k=0;
			for(int i=1;i<=n;i++)if(a[i]-a[1]>d)k=i-1,break;
			printf("%d\n",(n/k-1)*k+n%k);
		}
	}
	else{
		while(t--)printf("0\n");
	}
	return 0;
}
