#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
long long w[1000086];
int k[505];
struct P{
	int a;
	long long t;
};
//vector<P> l[505];
long long mt[505][505];
vector<P> v[1000086];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c ,&n ,&m ,&d ,&q);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &w[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &k[i]);
		int tmp1;
		long long tmp2;
		for(int j = 1; j <= k[i]; j++){
			scanf("%d%lld", &tmp1, &tmp2);
//			l[i].push_back({tmp1,tmp2});
			v[tmp1].push_back({i,tmp2});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			mt[i][j] = 1e9+7;
		}
	}
	int a, b;
	for(int i = 1; i <= m; i++){
		if(v[i].size()==1) continue;
//		printf("~%d\n", i);
		for(int j = 0; j < v[i].size(); j++){
			for(int k = 0; k < v[i].size(); k++){
				a = v[i][j].a;
				b = v[i][k].a;
				if(a == b) mt[a][a] = 0;
				mt[a][b] = mt[b][a] = min(mt[a][b], v[i][j].t+v[i][k].t);
//				printf("*%d %d %d %d %d %d\n",i, j,k, v[i][j].t, v[i][k].t, mt[a][b]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(i == j || i == k || j == k) continue;
				mt[j][k] = mt[k][j] = min(mt[j][k], mt[j][i]+mt[k][i]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(i == j || i == k || j == k) continue;
				mt[j][k] = mt[k][j] = min(mt[j][k], mt[j][i]+mt[k][i]);
			}
		}
	}
	if(c>=9&&c<=11||c>=16){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(i == j || i == k || j == k) continue;
					mt[j][k] = mt[k][j] = min(mt[j][k], mt[j][i]+mt[k][i]);
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int k = 1; k <= n; k++){
					if(i == j || i == k || j == k) continue;
					mt[j][k] = mt[k][j] = min(mt[j][k], mt[j][i]+mt[k][i]);
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++){
//			printf("%d ",mt[i][j]);
//		}
//		printf("\n");
//	}
	int x,y;
	while(q--){
		scanf("%d%d", &x, &y);
		long long ans = 1e9+7;
		for(int i = 0; i < v[x].size(); i++){
			for(int j = 0; j < v[y].size(); j++){
				ans = min(ans, v[x][i].t+v[y][j].t+mt[v[x][i].a][v[y][j].a]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
