#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int mn=500003;
	long long a[mn];
	int main(){
		int n,lp=1,ma=0;
		long long m,now=0;
		scanf("%d%lld",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			now+=(i-lp)*(a[i]-a[i-1]);
			while(now>m){
				now-=a[i]-a[lp];
				lp++;
			}
			ma=max(ma,i-lp+1);
		}
		printf("%d",ma);
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	estidi::main();
	return 0;
}
