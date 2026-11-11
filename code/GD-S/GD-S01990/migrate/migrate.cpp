#include <bits/stdc++.h>
#define int long long
using namespace std;
int shuju,T,n,d,k,ans,a[2000020];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&shuju,&T);
	while(T--){
		ans=0;
		scanf("%lld %lld",&n,&d);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(a[j]-a[i]>d)
					ans=ans+1;
		printf("%lld\n",ans);
	}
	return 0;
}
