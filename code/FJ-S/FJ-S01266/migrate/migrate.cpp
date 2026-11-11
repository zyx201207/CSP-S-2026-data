#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
typedef long long ll;

int c,T;
ll n,d,x[N];
ll f[5005][5005],g[5005][5005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	if(0 <= c && c <= 10){
		while(T--){
			scanf("%lld %lld",&n,&d);
			for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
			ll ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j  = 1; j <= n; j++) f[i][j] = 2e18,g[i][j] = 1;
			}
			for(int i = 1; i <= n; i++){
				f[i][i] = 0;
				for(int j = i + 1; j <= n; j++){
					int id = j;
					while(i < id && x[j] - x[id - 1] <= d){
						id--;
						if(f[i][j] > f[i][id]){
							f[i][j] = f[i][id];
							g[i][j] = g[i][id];
						}else if(f[i][j] == f[i][id]){
							g[i][j] += g[i][id];
						}
					}
					if(g[i][j] == 2) ans++;
					f[i][j]++;
				}
			}
			printf("%lld\n",ans);
		}
	}else if(11 <= c && c <= 12){
		while(T--){
			scanf("%lld %lld",&n,&d);
			for(int i = 1; i <= n; i++) scanf("%lld",&x[i]);
			ll delta = x[2] - x[1],mx = d / delta;
			ll ans = 0;
			if(mx == 0) printf("0\n");
			else{
				for(ll i = 1; i <= n; i++){
					if(i % mx && i > mx + 1) ans += mx;
				}
				printf("%lld %lld\n",n,ans);
			}
		}
	}
	return 0;
}
