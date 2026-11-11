#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,ans;
	scanf("%lld%lld",&c,&t);
	if(c>=11&&c<=12)
		while(t--){
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",x+i);
			if(d/(x[2]-x[1])<2||n<d/(x[2]-x[1])*2)printf("0\n");
			else printf("%lld\n",n-d/(x[2]-x[1])*2+1);
		}
	return 0;
}
