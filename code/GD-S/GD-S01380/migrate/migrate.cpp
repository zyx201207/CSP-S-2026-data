#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		bool flag=false;
		for(int i=2;i<=n;i++)
			if(a[i]-a[i-1]<=d){
				flag=true;
				break;
			}
		if(!flag||n<4){
			printf("0\n");
			continue;
		}
		printf("%lld\n",n-3);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
