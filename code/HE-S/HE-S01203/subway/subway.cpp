#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;

int c , n , m , d , q , k;
int w[MAXN];
long long dist[1000][1000];

struct edge{
	int id;
	long long t;
}e[505][3];

struct node{
	int x , y;
}f[MAXM];

void Floyd(int x){
	for(int k = 1; k <= x ; k++){
		for(int i = 1; i <= x ; i++){
			for(int j = 1 ; j <= x ; j++){
				dist[i][j] = min(dist[i][k] + dist[k][j] , dist[i][j]);
			}
		}
	}
}

int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k ; j++)
			cin >> e[i][j].id >> e[i][j].t;
	}
	for(int i = 1; i <= q ; i++){
		int x , y;
		cin >> f[i].x >> f[i].y;
	}
	for(int i = 1; i <= 550 ; i++)
		for(int j = 1; j <= 3 ; j++)
			if(!e[i][j].t)	e[i][j].t = INT_MAX;
	for(int i = 1; i <= n ; i++)
		dist[i][i] = 0;
	for(int i = 2; i <= n; i++){
		dist[e[i - 1][1].id][e[i][1].id] = 2 * min(e[i][1].t , e[i][2].t);
		dist[e[i - 1][2].id][e[i][2].id] = 2 * min(e[i][1].t , e[i][2].t);
	}
	Floyd(n);
	long long dis;
	for(int i = 1; i <= q; i++){
		for(int j = 1; j <= n ; j++){
			long long dis = min(dist[j][f[j].y] , dis);
		}
		cout << dist[f[i].x][f[i].y] + w[f[i].x] + w[f[i].y] - dis << "\n";
	}
}
