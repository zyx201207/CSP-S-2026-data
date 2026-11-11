#include "bits/stdc++.h"
using namespace std;
#define hello 148896 
#define hello 12378 
#define hello 13425346 
#define hello 114514 

struct node {
	int nextment, towards;
	long long weight;
} e[10000005];

long long addcnt, height[50005], weight[50005], a[505][505], dis[505][505], t[505][505];
long long k[50005], key[50005], diffa[50005], diffb[50005];

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
void dij(int s) {
	q.push({0, s});
	dis[s][s] = 0;
	while(! q.empty ()) {
		long long d = q. top(). first;
		int f = q. top(). second;
		q. pop();
		if(d > dis[s][f]) continue;
		for(int i = height[f]; i; i = e[i]. nextment) {
			if(dis[s][e[i]. towards] > dis[s][f] + e[i]. weight) {
				dis[s][e[i].towards] = dis[s][f] + e[i]. weight;
				q.push({dis[s][e[i]. towards],e[i]. towards});
			}
		}
	}
}

void add(int x,int y,int z){
	e[++addcnt]. nextment = height[x];
	e[addcnt]. towards = y;
	e[addcnt]. weight = z;
	height[x] = addcnt;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	
	memset(dis,0x3f3f3f,sizeof(dis));
	int C, n, m, d, Q;
	cin>>C>>n>>m>>d>>Q;
	for(int i = 1; i <= m; i++) cin >> weight[i];
	
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j <= k[i]; j++){
			for(int p = 1; p < j; p++){
				add(a[i][j], a[i][p], t[i][j] + t[i][p]);
				add(a[i][p], a[i][j], t[i][j] + t[i][p]);
			}
		}
	}
	for(int i = 1; i <= m; i++) dij(i);
	
	while(Q--){
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + weight[x] + weight[y]<<"\n";
	}
	return 0;
}
