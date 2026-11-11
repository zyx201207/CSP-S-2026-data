#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int c,n,m,d,q,W[N],tot[N],b[N][21];
ll dp[505][505],w[N][21];
vector <int> g[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(i ^ j)dp[i][j] = 1e17;
		}
	}
	for(int i = 1;i <= m;i ++)cin >> W[i];
	for(int i = 1,k;i <= n;i ++){
		cin >> k;
		for(int j = 1,y,val;j <= k;j ++){
			cin >> y >> val;
			b[y][++ tot[y]] = i;
			w[y][tot[y]] = val;
		}
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= tot[i];j ++){
			for(int k = j + 1;k <= tot[i];k ++){
				int J = b[i][j],K = b[i][k];
				dp[J][K] = dp[K][J] = min(dp[J][K],w[i][j] + w[i][k]);
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			for(int k = 1;k <= n;k ++){
				dp[j][k] = min(dp[j][i] + dp[i][k],dp[j][k]);
			}
		}
	}
	while(q --){
		ll ans = 1e17,x,y;
		cin >> x >> y;
		for(int i = 1;i <= tot[x];i ++){
			for(int j = 1;j <= tot[y];j ++){
				ans = min(ans,w[x][i] + w[y][j] + dp[b[x][i]][b[y][j]]);
			}
		}
		ans += W[x] + W[y];
		cout << ans << '\n';
	}
	return 0;
}
