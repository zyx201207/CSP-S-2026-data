#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505,MAXM = 2e4 + 5;
//  无用   线   站  站有几条线   问题数 
int c    ,  n,   m,   d          ,q; 
//  口->厅    线  -> 台 
int w[MAXM],t[MAXN][MAXM];
//     台 -> 台 
int floyd[MAXM][MAXM]; 
//线 
vector<int> line[MAXN]; 
//站拥有的线 
vector<int> sta[MAXM];
//问题 

int main() {
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(floyd,0x3f,sizeof(floyd));
	for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
	for(int i = 1;i <= n;i++) {
		int k;
		scanf("%d",&k);
		for(int j = 1;j <= k;j++) {
			int x;
			scanf("%d",&x);
			scanf("%d",&t[i][x]);		
			line[i].push_back(x);
			sta[x].push_back(i);
		}
	}
	
	for(int i = 1;i <= n;i++) {
		for(auto u : line[i])
			for(auto v : line[i]) {
				if(u != v) floyd[u][v] = floyd[v][u] = min(floyd[u][v],t[i][u] + t[i][v]);
			}
	}
	
	for(int k = 1;k <= m;k++)
		for(int i = 1;i <= m;i++)
			for(int j = 1;j <= m;j++) 	
				if(i != j) floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
	
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",floyd[x][y] + w[x] + w[y]);
	}
} 
