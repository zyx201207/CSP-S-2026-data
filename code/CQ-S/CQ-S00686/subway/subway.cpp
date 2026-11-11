#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
//
//
//
using namespace std;
inline int read() {
	int sum = 0, f = 0;
	char c = getchar();
	while(!isdigit(c)) f |= (c == '-'), c = getchar();
	while(isdigit(c)) sum = (sum<<1) + (sum << 3) + c - 48, c = getchar();
	return f ? -sum: sum;
}
const int MX = 5e5 + 10;
int c,n,m,d,q;
int w[MX], len[MX];
struct sky {
	int x,w;
};
basic_string<sky>s[505];
basic_string<sky>D[MX];
int vis[MX];
int Dis[505][505];
int cnt[MX];
const int MM = 1e18 + 10;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	FOR(i,1,m) w[i] = read();
	FOR(i,1,n) {
		len[i] = read();
		FOR(j,1,len[i]) {
			int a = read(), b = read();
			s[i] += (sky) {
				a,b
			};
			D[a]+=(sky) {
				i,b
			};
		}
	}
	FOR(i,0,500) FOR(j,0,500) if(i != j) Dis[i][j] = MM;
	else Dis[i][j] = 0;
	FOR(i,1,n) {
		FOR(j,0,s[i].size() - 1) vis[s[i][j].x] = s[i][j].w;
		FOR(j,i + 1, n) {
			FOR(k,0,s[j].size() - 1) if(vis[s[j][k].x] != 0) {
				Dis[i][j] = min(Dis[i][j], vis[s[j][k].x] + s[j][k].w);
				Dis[j][i] = min(Dis[j][i], vis[s[j][k].x] + s[j][k].w);
			}
		}
		FOR(j,0,s[i].size() - 1) vis[s[i][j].x] = 0;
	}//优雅的暴力
	FOR(i,1,n) FOR(j,1,n) {
		if(i == j) continue;
		FOR(k,1,n) {
//			if(k == i || k == j) continue;
			Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
			Dis[j][i] = Dis[i][j];
		}
	}
	//优雅的floyd
//	FOR(i,1,n) FOR(j,1,n) cout<<i<<" "<<j<<" "<<Dis[i][j]<<"\n";
	FOR(i,1,q) {
		int a = read(), b = read();
		int ans = MM;
		FOR(j,0,D[a].size() - 1) FOR(k,0,D[b].size()- 1) {
//			cout<<
//			    Dis[D[a][j].x][D[b][k].x] + w[a] + w[b]+ D[a][j].w + D[b][k].w<<"\\\\ "<<Dis[D[a][j].x][D[b][k].x]<<" "
//			    <<D[a][j].x<<" "<<D[b][k].x<<" "
//			    <<a<<" "<<b<<" "
//			    <<D[a][j].w<<" "<<D[b][k].w<<"\n";
			ans = min (ans,
			           Dis[D[a][j].x][D[b][k].x] + w[a] + w[b]+ D[a][j].w + D[b][k].w);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
如果存在 计算算第 i 条线到第 j 条线的最小费用
就爆枚 500 * 500000 1E8以内应该问题不大
然后用弗洛伊德把任意俩线最短距离跑出来 500 * 500 * 500
最后查询 爆力过 i 站点的所有线 到 过 j 站台所有线的最小值 然后输出
要开 ll
*/
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
