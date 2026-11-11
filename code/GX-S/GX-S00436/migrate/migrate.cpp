# include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c, t;
ll n, d, x[2000005];
typedef struct Graph{
	ll data[5005];
	ll road[5005][5005];
	ll size, edge;
}Graph;
void Initial(Graph* G){
	G->size = G-> edge = 0;
	return;
}
void Insert(Graph* G, ll a){
	G->data[G->size++] = a;
	return;
}
ll GetPos(Graph* G, ll a){
	ll i = 0;
	while(1){
		if(G->data[i] == a) break;
		i++;
	}
	return i;
}
void InsertEdge(Graph* G, ll a, ll b){
	ll k = GetPos(G, a), l = GetPos(G, b);
	if(k == -1 || l == -1) return;
	ll en = x[k] - x[l];
	G->road[k][l] = G-> road[l][k] = en >= 0 ? en : -en;
	return;
}
void Print(Graph* G){
	printf("VerTex\t");
	for(int i = 0; i < n; i++){
		printf("%lld\t", G->data[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%lld\t", G->data[i]);
		for(int j = 0; j < n; j++){
			printf("%lld\t", G->road[i][j]);
		}
		printf("\n");
	}
	return;
}
int main(void){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	//Graph* G;
	scanf("%lld %lld", &c, &t);
	while(t--){
		cin >> n >> d;
		memset(x, 0, n);
		for(ll i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
			//Insert(G, x[i]);
		}
	}
	
	return 0;
}
