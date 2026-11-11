#include <bits/stdc++.h>
using namespace std;

int c , T , vis[2000010] , q[4010][4010];
void dfs(int u , int v , int fa , int step){
	if(u == v){
		vis[step]++;
		return;
	}for(int i = 1 ; i <= n ; i++){
		if(!q[u][i] || i == fa) continue;
		dfs(i , v , u , step + 1)
	}
}

int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> T;
	while(T--){
		int n , d , a[2000010] , fst , cnt = 0;
		cin >> n >> d >> a[1] , fst = 1;
		int q[n + 10][n + 10];
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				q[i][j] = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i];
			while(d < (a[i] - a[fst])) fst++;
			for(int j = fst ; j <= i ; j++)
				for(int k = fst ; k <= i ; k++)
					q[j][k] = q[k][j] = 1;
		}for(int i = 1 ; i < n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				dfs(i , j , 0 , 0);
				while(vis[++vis[0]] == 0);
				if(++vis[0] != 1 && vis[++vis[0]] == 2) cnt++;
				for(int k = 0 ; k <= n ; k++) vis[i] = 0;
			}
		}cout << cnt << endl;
	}
	return 0;
}
 
