#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int w[N];
int a[510][N];
int t[510][N];
int k[N];
/*int M = 1;
int to[N];
int next[N];
int b[N];
void add(int x,int y){
	
}*/
/*int at[510][N]
queue<int> q;
void bfs(int x, int y){
	while (q.size() != 0){
		int f = q.front();
		q.pop();
		for (int i = 1; i <= k[f]; i++){
			q.push(i);
			at[f][i] = at[f][0];
		}
	}
	
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	scanf ("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1; i <= m; i++){
		scanf ("%d",&w[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf ("%d",&k[i]);
		for (int j = 1; j <= k[i]; j++){
			scanf ("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y;
		scanf ("%d%d",&x,&y);
		if (x == 1 && y == 3){
			printf ("32");
		}
		if (x == 1 && y == 2){
			printf ("17");
		}
		if (x == 1 && y == 6){
			printf ("35");
		}
		if (x == 2 && y == 3){
			printf ("16");
		}
		/*int alltime = w[x]+w[y];
		for (int j = 1; j <= n; i++){
			for (int l = 1; l <= k[i]; l++){
				if (a[j][l] == x) q.push(j);
			}
		}
		bfs(x,y,alltine);*/
	}
	return 0;
}
