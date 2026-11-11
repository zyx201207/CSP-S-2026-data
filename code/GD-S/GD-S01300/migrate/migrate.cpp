#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,ans;
int a[N];
signed main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	int _t,_id;
	scanf("%lld %lld",&_id,&_t);
	while(_t--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(n<4){
			puts("0");
			continue;
		}
		ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]<=d || a[i+3]-a[i]>(2*d) || a[i+2]-a[i]>d || a[i+3]-a[i+1]>d || a[i+1]-a[i]>d || a[i+2]-a[i+1]>d || a[i+3]-a[i+2]>d)continue;
			int l1,l2;
			l1=l2=1;
			while(a[i-l1+2]-a[i-l1]>d && a[i-l1+1]-a[i-l1]<=d && i-l1>=0)
				l1++;
			while(a[i+4+l2]-a[i+2+l2]>d && a[i+3+l2]-a[i+2+l2]<=d && i+4+l2<=n)
				l2++;
//			printf("Have!!\nfrom::%lld\nfind::%lld %lld\n",i,l1,l2);
			ans+=l1*l2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// ???WA???  [Good] 
