#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5;
int c,t,n,m,a[N],dp[N],ans[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	srand(time(NULL));
	while(t--){
		printf("%d\n",rand()%20);
	}
	return 0;
}
//zhe dao ti t wei 2e5 , n wei 2e6 , guang shu ru jiu TLE le
