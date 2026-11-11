#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infLL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int,int> pii;

inline int read(){
	int c;
	int num = 0;
	do{
		c = getchar();
//		cout<<"rd:"<<(char)c<<'\n';
	}while(c == ' ' || c == '\n');
	//if(c == '-') mul = -1;
	/*else */num = (c^48);
	c = getchar();
	while('0' <= c && c <= '9'){
//		cout<<"rd:"<<(char)c<<'\n';
		num = num*10 + (c^48);
//		cout<<"num="<<num<<'\n';
		c = getchar();
	}
//	cout<<"rd:"<<(char)c<<'\n';
	return num;
}

char bufc[22];
int bfccnt;
inline void write(ll z){
//	if(z < 0){
//		putchar('-');
//		z = -z;
//	}
	bfccnt = 0;
	while(z){
		bufc[bfccnt++] = (char)((z%10)|48);
		z = z / 10;
//		cout<<"now x="<<x<<'\n';
	}
	while(bfccnt){
		putchar(bufc[--bfccnt]);
	}
}

inline ll min(ll a, ll b){
	if(a > b) return b;
	return a;
}

const int maxn = 505;
const int maxm = 5e5+5;

struct edge{
	int v; ll w;
};
vector<edge> G[maxm];
ll dp[maxn][maxn];
int outerw[maxm];

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c, n, m, d, q;
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int u=1;u<=m;u++){
		outerw[u] = read();
	}
//	cout<<"zwz\n";
	for(int v=1;v<=n;v++){
		int k;
		k = read();
		for(int i=1;i<=k;i++){
			int u, w;
			u = read();
			w = read();
			G[u].push_back({v, (ll)w});
		}
	}
//	cout<<"awa\n";
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j] = infLL;
		dp[i][i] = 0;
	}
	for(int u=1;u<=m;u++){
		int sz = G[u].size();
		if(sz <= 1) continue;
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				edge E1 = G[u][i], E2 = G[u][j];
				dp[E1.v][E2.v] = min(dp[E1.v][E2.v], E1.w+E2.w);
			}
		}
		
//		//debug
//		cout<<"after adding "<<u<<", dp:\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++) cout<<setw(15)<<dp[i][j]<<' ';
//			cout<<'\n';
//		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
			}
		}
	}
//	//debug
//	cout<<"in the end, dp:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++) cout<<setw(15)<<dp[i][j]<<' ';
//		cout<<'\n';
//	}
	
	while(q--){
		int x, y;
		x = read();
		y = read();
		ll ans = infLL;
		for(int i=0;i<G[x].size();i++){
			for(int j=0;j<G[y].size();j++){
				edge E1 = G[x][i], E2 = G[y][j];
				ans = min(ans, dp[E1.v][E2.v] + E1.w + E2.w);
			}
		}
		ans += (ll)outerw[x] + outerw[y];
		write(ans);
		putchar('\n');
	}
	
	return 0;
}
