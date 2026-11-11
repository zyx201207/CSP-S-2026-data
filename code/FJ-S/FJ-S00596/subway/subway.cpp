// also check long long & freopen
// check 数据范围 
// floyd O(n^3)
// 题面越来越难读了（ 

#include <bits/stdc++.h>
using namespace std;

const int N=509, M=500009;

int C, n, m, d, q, w[M];
vector<int> a[M];
vector<int> t[M];

long long dis[N][N];

int main(){
//	system("fc test.txt subway7.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	scanf("%d%d%d%d%d", &C, &n, &m, &d, &q);
	for (int i=1; i<=m; i++)	scanf("%d", &w[i]);
	for (int i=1; i<=n; i++){
		int k;
		scanf("%d", &k);
		while (k--){
			int x, y; // x为站点 i为线路 
			scanf("%d%d", &x, &y);
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for (int i=1; i<=n; i++)	dis[i][i]=0;
	for (int i=1; i<=m; i++){
		for (int j=0; j<a[i].size(); j++)
			for (int k=j+1; k<a[i].size(); k++){
				int a1=a[i][j], a2=a[i][k];
				dis[a1][a2]=dis[a2][a1]=min(dis[a1][a2], (long long)t[i][j]+t[i][k]);
			}
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
	
	while (q--){
		int x, y;
		scanf("%d%d", &x, &y);
		
		long long ans=1e18;
		for (int i=0; i<a[x].size(); i++)
			for (int j=0; j<a[y].size(); j++){
				int a1=a[x][i], a2=a[y][j];
				ans=min(ans, t[x][i]+dis[a1][a2]+t[y][j]);
			}
		
		printf("%lld\n", ans+w[x]+w[y]);
	}
	return 0;
}
