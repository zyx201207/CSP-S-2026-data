#include<bits/stdc++.h>
using namespace std;
#define N 505
#define M 500005
#define intl long long
#define inf (0x3f3f3f3f3f3f3f3f)
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
	intl x=0,k=1;char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') k = -1; ch = getchar();}
	while(isdigit(ch)) x = (x<<3)+(x<<1)+(ch^48), ch = getchar();
	return x*k;
}
intl c,n,m,d,q, dis[N][N], w[M];
vector<pair<intl,intl>> vec[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	For(i,1,m) w[i] = read();
	For(i,1,n) For(j,1,n) dis[i][j] = inf;
	For(i,1,n) dis[i][i] = 0;
	For(i,1,n) {
		intl k = read();
		while(k --) {
			intl a = read(), t = read();
			for(auto qwe:vec[a]) {
				intl v = qwe.first, val = qwe.second;
				dis[i][v] = dis[v][i] = min(dis[i][v], t+val);	
			}
			vec[a].push_back({i, t});
		}
	}
	For(k,1,n) For(i,1,n) For(j,1,n) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q --) {
		intl x = read(), y = read();
		intl ans = inf;
		for(auto qwex:vec[x]) for(auto qwey:vec[y]) {
			intl vx = qwex.first, valx = qwex.second, vy = qwey.first, valy = qwey.second;
			ans = min(ans, w[x]+w[y]+valx+valy+dis[vx][vy]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
