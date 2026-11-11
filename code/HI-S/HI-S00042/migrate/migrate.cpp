#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2 * 1e6 + 5;
long long a[N] = {},dp[N] = {};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t -- ){
		int n;
		ll d;
		map <ll,int> mp;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mp[a[i]] = i;
		}
		int pos = 1;
		while(a[pos] - a[1] <= d){
			dp[pos] = 1;
			pos += 1;
		}
		int ans = 0;
		for(int i=pos;i<=n;i++){
			dp[i] = 0;
			for(int j=1;j<=d;j++){
				if(mp[a[i] - j] >= 1)
					dp[i] = dp[i] + dp[mp[a[i] - j]];
				//if(mp[a[i] - j] - a[1] <= d)
				//	break;
			}
			if(dp[i] == 2)
				ans += 1;
		}
		//for(int i=1;i<=n;i++)
			//cout<<dp[i]<<' ';
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
