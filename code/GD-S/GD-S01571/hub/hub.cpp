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
const int INF = 0x3f3f3f3f3f3f3f3f;
int c,n,k;
vector <int> vec[1000005];
int dp[4005][4005];
void dfs(int u,int fa,int maxdis){
	dp[u][0] = 1;
	int siz = vec[u].size();
	if (siz == 0) dp[u][1] = 0;
	for (int i = 0;i < siz;i++){
		int v = vec[u][i];
		if (v == fa) continue;
		int res = INF;
		for (int j = 1;j <= maxdis;j++){
			dp[u][j] += dp[v][j - 1];
			res = min(res,dp[v][j]);
		}
		dp[u][0] += res;
	}
}

bool check(int x){
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0,x);
	int minn = INF;
	for (int i = 0;i <= x;i++) minn = min(minn,dp[1][i]);
	return (minn <= k);
}

void shuqiangakioi(){
	n = fr(),k = fr();
	for (int i = 1;i <= n;i++) vec[i].clear(),vec[i].shrink_to_fit();
	for (int i = 1;i < n;i++){
		int u = fr(),v = fr();
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int L = 1,R = n;
	while (L <= R){
		int mid = (L + R) >> 1;
		if (check(mid)) R = mid - 1;
		else L = mid + 1;
	}
	fw(L),putchar('\n');
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = fr();
	int t = fr();
	while (t--) shuqiangakioi();
	return 0;
}
