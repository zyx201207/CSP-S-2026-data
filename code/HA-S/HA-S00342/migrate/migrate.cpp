#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
ll n,d;
ll ans,Min;
ll a[20005];
ll dis[2005][2005],cnt[2005][2005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		Min = 1e18+1;
		ans = 0;
		for(int i = 1;i <= n;i ++){
			scanf("%lld",&a[i]);
			Min = min(Min,a[i]);
		}
		Min = abs(Min);
		for(int i = 1;i <= n;i ++) a[i] += Min;
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
				dis[a[i]][a[j]] = a[j]-a[i];
				if(a[i]+d >= a[j]){
					dis[a[i]][a[j]] = 1;
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
				for(int k = i+1;k < j;k ++){
					if(a[k]+d >= j){
						if(dis[a[i]][a[j]] == dis[a[i]][a[k]]+1){
							cnt[a[i]][a[j]] ++;
						} else if(dis[a[i]][a[j]] > dis[a[i]][a[k]]+1){
							dis[a[i]][a[j]] = dis[a[i]][a[k]]+1;
							cnt[a[i]][a[j]] = 1;
						}
					}
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
//					cout<<cnt[a[i]][a[j]]<<" ";
				if(cnt[a[i]][a[j]] == 2){
//					cout<<i<<" "<<j<<"\n";
					ans ++;
				}
			}
			cout<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


1
2


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0
1
*/
