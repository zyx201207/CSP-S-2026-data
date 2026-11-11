#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Fast{
	inline int fr(){
		int x = 0,f = 1;
		char c = getchar();
		while (c < '0' || c > '9'){
			if (c == '-') f = 0;
			c = getchar();
		}
		while (c >= '0' && c <= '9'){
			x = (x << 1) + (x << 3) + (c ^ 48);
			c = getchar();
		}
		return (f ? x : -x);
	}
	char putstk[1005];
	inline void fw(int x){
		if (x == 0) return putchar('0'),void();
		if (x < 0) x = -x,putchar('-');
		int tp = 0;
		while (x) putstk[++tp] = ((x % 10) ^ 48),x /= 10;
		while (tp) putchar(putstk[tp--]);
	}
}

using namespace Fast;
const int MAXM = 5e5 + 5;
const int MAXN = 505;
const int INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[MAXM],cnt[MAXM],idx[MAXM][25],tdis[MAXM][25],maxid;
int dp[MAXN][MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = fr(),n = fr(),m = fr(),d = fr(),q = fr();
	for (int i = 1;i <= m;i++) w[i] = fr(),cnt[i] = 0;
	maxid = m;
	for (int i = 1;i <= n;i++){
		int len = fr();
		for (int j = 1;j <= len;j++){
			int a = fr(),t = fr();
			cnt[a]++;
			idx[a][cnt[a]] = i;
			tdis[a][cnt[a]] = t;
			int nowid = cnt[a] * m + a;
			maxid = max(maxid,nowid);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for (int i = 0;i <= n;i++) dp[i][i] = 0;
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= cnt[i];j++){
			for (int k = j + 1;k <= cnt[i];k++){
				int x = idx[i][j],y = idx[i][k];
				dp[x][y] = min(dp[x][y],tdis[i][j] + tdis[i][k]);
				dp[y][x] = min(dp[y][x],tdis[i][j] + tdis[i][k]);
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int u = fr(),v = fr();
		int ans = INF;
		for (int j = 1;j <= cnt[u];j++){
			for (int k = 1;k <= cnt[v];k++){
				int x = idx[u][j],y = idx[v][k];
				int res = w[u] + w[v] + tdis[u][j] + tdis[v][k];
				ans = min(ans,res + dp[x][y]);
			}
		}
		fw(ans),putchar('\n');
	}
	return 0;
}
