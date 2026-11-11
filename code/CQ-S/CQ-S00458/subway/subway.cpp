#include <bits/stdc++.h>
#define re register
#define fst first
#define snd second
#define int long long
#define chmin(a,b) (a = min(a,b))

using namespace std;

typedef pair<int,int> pii;
const int N = 510,M = 5e5 + 10,inf = (int)(1e18) + 10;
int cid,n,m,D,Q;
int w[M],trans[N][N];
vector<pii> st[M];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cid = read(),n = read(),m = read(),D = read(),Q = read();
	for (re int i = 1;i <= m;i++) w[i] = read();
	for (re int i = 0;i <= n + 3;i++) fill(trans[i],trans[i] + n + 3,inf);
	for (re int i = 1;i <= n;i++) trans[i][i] = 0;
	for (re int i = 1,num;i <= n;i++){
		num = read();
		while (num--){
			int j = read(),k = read();
			st[j].push_back({i,k});
		}
	}
	for (re int i = 1;i <= m;i++){
		for (pii u:st[i]){
			for (pii v:st[i]) chmin(trans[u.fst][v.fst],u.snd + v.snd);
		}
	}
	for (re int k = 1;k <= n;k++){
		for (re int i = 1;i <= n;i++){
			for (re int j = 1;j <= n;j++) chmin(trans[i][j],trans[i][k] + trans[k][j]);
		}
	}
	while (Q--){
		int x = read(),y = read(),ans = inf;
		for (pii u:st[x]){
			for (pii v:st[y]) chmin(ans,u.snd + v.snd + trans[u.fst][v.fst]);
		} printf("%lld\n",ans + w[x] + w[y]);
	}
	return 0;
}

/*
trans[i][j] 表示从 i 号线转到 j 号线所需时间 
time = w[x] + w[y] + trans + ....
*/
