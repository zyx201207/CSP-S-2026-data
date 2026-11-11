#include<bits/stdc++.h>
using namespace std;

int c,t,mi[3001][30001],ans[3001][3001];

const void dfs(int x,int yx,int y,int d, int dis){
	if (x == y){
		if (dis < mi[yx][y])
			mi[yx][y] = dis;
		if (dis = mi[yx][y])
			ans[yx][y]++;
	}
	for (int i = 1; i <= d; i++){
		dfs(x + i, yx, y, d, dis + 1);
		dfs(x - i, yx, y, d, dis + 1);
	}
}

int main(){
	printf("1");
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,d,a[2000001],sum = 0;
		scanf("%d%d", &n,&d);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dfs(i,i,j,d,0);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (ans[i][j] == 2)
					sum++;
		printf("%d\n", sum);
	}
}
