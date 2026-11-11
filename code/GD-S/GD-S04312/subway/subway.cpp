#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
	while(isdigit(ch)){s = s * 10 + ch - '0';ch = getchar();}
	return s * f;
}
const int MAXN = 505, MR = 5e5 + 5, INF = 1e18;
int c, n, m, d, q, w[MR], len[MAXN], f[MAXN][MAXN];//f[i][j]表示从i线路到j的最短时间 
struct node{
	int x, val;
};
vector <node> vc[MR];//记录每一个地铁站的线路信息
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1;i <= m;i ++)w[i] = read();
	memset(f, 0x3f, sizeof(f));
	for(int i = 1;i <= n;i ++){
		len[i] = read();
		for(int j = 1;j <= len[i];j ++){
			int x = read(), y = read();
			vc[x].push_back({i, y});
		}
	}
	for(int i = 1;i <= m;i ++){
		for(node x : vc[i]){
			for(node y : vc[i]){
				if(x.x == y.x)continue;
				f[x.x][y.x] = min(f[x.x][y.x], x.val + y.val);
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		for(int k = 1;k <= n;k ++){
			for(int j = 1;j <= n;j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		}
	}
	for(int i = 1;i <= n;i ++)f[i][i] = 0;
	while(q --){
		int l = read(), r = read(), res = INF;
		for(node x : vc[l]){
			for(node y : vc[r])
				res = min(res, x.val + y.val + f[x.x][y.x]);
		}
		printf("%lld\n", res + w[l] + w[r]);
	}
	return 0;
}

