#include<bits/stdc++.h>
using namespace std;
// constexpr int N = 5e5 + 509, S = 509;
int C, n, m, d, q;
struct Edge{
	int v;
	long long w;	
};
vector<Edge> e[500509];
long long www[500509];

void addedge(int u, int v, long long w){
	e[u].push_back(Edge{v, w});
}


long long trdis[509][509];

int readI(){
	char c = 0;
	int ret = 0;
	while((c < '0') || (c > '9')){
		c = getchar();
	}
	while(('0' <= 'c') && (c <= '9')){
		ret = (ret << 1) + (ret << 3) + (c ^ 48);
		c = getchar();
		if((c < '0') || (c > '9')){break;}
	}
	return ret;
}
long long readLL(){
	char c = 0;
	long long ret = 0;
	while((c < '0') || (c > '9')){
		c = getchar();
	}
	while(('0' <= 'c') && (c <= '9')){
		ret = (ret << 1) + (ret << 3) + (c ^ 48);
		c = getchar();
		if((c < '0') || (c > '9')){break;}
	}
	return ret;
}
void print(long long x){
	if(x == 0){
		putchar('0');
		putchar('\n');
		return;
	}
	char ret[66];
	int cnt = 0;
	while(x){
		ret[cnt++] = (x % 10) ^ 48;
		x /= 10;
	}
	for(int i=cnt; i; i--){
		putchar(ret[i - 1]);
	}
	putchar('\n');
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//input: O(m + sigma(k))
	C = readI(); n = readI(); m = readI(); d = readI(); q = readI();
	//scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1; i<=m; i++){
		www[i] = readLL();
		//scanf("%lld", &www[i]);
	}
	for(int i=1; i<=n; i++){
		int k = readI();
		//scanf("%d", &k);
		for(int j=0; j<k; j++){
			int a = readI();
			long long t = readLL();
			//scanf("%d%lld", &a, &t);
			addedge(a, i, t);// to trains -> lines
		}
	}
	
	//initialize: O(n^2 + m*k^2)
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i != j){
				trdis[i][j] = 0x3f3f3f3f3f3f3f3f;
			} 
		}
	}
	for(int i=1; i<=m; i++){
		for(auto U: e[i]){
			long long WW = U.w;
			int u = U.v; // line A
			for(auto V: e[i]){
				int v = V.v; // line B
				long long ww = V.w;
				if(u == v){
					trdis[u][v] = 0;
					trdis[v][u] = 0;
				}else{
					trdis[u][v] = min(trdis[u][v], WW + ww);
					trdis[v][u] = min(trdis[v][u], WW + ww);
				}
			}
		}
	}
	
	// Floyd: O(n^3)
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				trdis[i][j] = min(trdis[i][j], trdis[i][k] + trdis[k][j]);
			}
		}
	}
	
	while(q--){
		int x = readI();
		int y = readI();
		//scanf("%d%d", &x, &y);
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for(auto U: e[x]){
			for(auto V: e[y]){
				ans = min(ans, U.w + V.w + trdis[U.v][V.v]);
			}
		}
		print(ans + www[x] + www[y]);
		//printf("%lld\n", ans + www[x] + www[y]);
	}
	
	return 0;
}

