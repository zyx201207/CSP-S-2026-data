#include <iostream>
#include <cstring>
#include <queue>
#include <stdio.h>
#define gc getchar()
using namespace std;
const int M = 5e5+10;
const long long inf = 1e17;
int c,n,m,d,p;
long long w[M] = {},t[M][25] = {},dis[505][505] = {},mind[505][505] = {};
int sta[M][25] = {},siz[M] = {};

inline long long read(){
	long long res = 0;
	char x;
	x = gc;
	while (x >= '0' && x <= '9'){
		res = res * 10 + (x - '0');
		x = gc;
	}
	return res;
}

void dij(int s){
	bool vis[505] = {};
	priority_queue <pair <long long,int> > q;
	mind[s][s] = 0;
	q.push(make_pair(0,s));
	while (!q.empty()){
		//cout << s << endl;
		int cur = q.top().second;
		q.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;
		for (int i = 1;i <= n;i++){
			if (i != cur && dis[cur][i] < inf){
				mind[s][i] = min(mind[s][i],mind[s][cur] + dis[cur][i]);
				q.push(make_pair(-mind[s][i],i));
			}
		}
	}
}

void prep(){
	memset(dis,63,sizeof(dis));
	memset(mind,63,sizeof(mind));
	for (int i = 1;i <= n;i++) mind[i][i] = dis[i][i] = 0;
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= siz[i];j++){
			for (int k = j+1;k <= siz[i];k++){
				dis[sta[i][j]][sta[i][k]] = min(dis[sta[i][j]][sta[i][k]],t[i][j]+t[i][k]);
				dis[sta[i][k]][sta[i][j]] = dis[sta[i][j]][sta[i][k]];
			}
		}
	} 
	for (int i = 1;i <= n;i++) dij(i);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c = read() ; n = read() ; m = read() ; d = read() ; p = read();
	for (int i = 1;i <= m;i++) w[i] = read();
	for (int i = 1;i <= n;i++){
		int k;
		k = read();
		for (int j = 1;j <= k;j++){
			int a;
			a = read();
			t[a][++siz[a]] = read();
			sta[a][siz[a]] = i;
		}
	}
	prep();
	for (int i = 1;i <= p;i++){
		int x,y;
		long long res = inf;
		x = read() ; y = read();
		for (int u = 1;u <= siz[x];u++){
			for (int v = 1;v <= siz[y];v++){
				//cout << mind[sta[x][u]][sta[y][v]] << ' ';
				res = min(res,mind[sta[x][u]][sta[y][v]]+t[x][u]+t[y][v]);
			}
		}
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}
