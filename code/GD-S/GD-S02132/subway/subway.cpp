#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int maxn = 1005;
const int maxm = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int c,n,m,d,q,k,a,t,b,a1,t1;
int w[maxn];
ull go[maxn][maxn],ans;
inline void solve1(){
	memset(go,0x3f,sizeof(go));
	for(int i = 1;i <= m;i++){
		w[i] = read();
	}
	for(int i = 1;i <= n;i++){ // 第i条线路 
		k = read();
		for(int j = 1;j <= k;j++){ // 第j座站点 
			a = read(),t = read();
			go[i][a + n] = t;
			go[a + n][i] = t;
		}
	}
	for(int i = 1;i <= n + m;i++){
		go[i][i] = 0;
	}
	for(int k = 1;k <= n + m;k++){
		for(int i = 1;i <= n + m;i++){
			if(k == i || go[i][k] == INF) continue;
			for(int j = 1;j <= n + m;j++){
				go[i][j] = min(go[i][j],go[i][k] + go[k][j]);
			}
		}
	}
	while(q--){
		a = read(),b = read();
		ans = go[a + n][b + n] + w[a] + w[b];
		printf("%llu\n",ans);
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read(),n = read(),m = read(),d = read(),q = read();
	solve1(); // 前8个能用Floyd做 
	return 0;
}
