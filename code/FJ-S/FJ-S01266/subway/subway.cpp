#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e5 + 5;
typedef long long ll;

int c,n,m,d,q;
ll w[N];
ll f[N][N];
vector <pair<ll,ll> > g[N],zd[N];
ll ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m; i++) scanf("%lld",&w[i]);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = f[j][i] = 2e18;
			}
		}
		for(int i = 1; i <= n; i++){
			int t;
			scanf("%d",&t);
			ll h1,h2,h3,h4;
			scanf("%lld %lld %lld %lld",&h1,&h2,&h3,&h4);
			if(h1 > h3) swap(h1,h3);
			f[h1][h3] = f[h3][h1] = min(f[h1][h3],h2 + h4);
		}
		for(int len = 2; len <= n; len++){
			for(int i = 1; i + len - 1 <= n; i++){
				int j = i + len - 1;
				for(int k = i + 1; k < j; k++){
					f[i][j] = f[j][i] = min(f[i][j],f[i][k] + f[k][j]);
				}
			}
		}
		while(q--){
			int s,t;
			scanf("%d %d",&s,&t);
			if(s > t) swap(s,t);
			ll ans = w[s] + w[t] + f[s][t];
			printf("%lld\n",ans);
		}
	return 0;
}
