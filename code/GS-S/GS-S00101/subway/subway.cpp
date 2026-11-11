#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int w[N];
int a[510][N];
int t[510][N];

int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	int c , n , m , d , q;
	scanf("%d%d%d%d%d" , &c , &n , &m , &d , &q);
	
	for(int i = 1 ; i <= m ; ++ i)
	{
		scanf("%d" , &w[i]);
	}
	for(int i = 1 ; i <= n ; ++ i)
	{
		int k;
		scanf("%d" , &k);
		for(int j = 1 ; j <= k ; ++ j)
		{
			scanf("%d%d" , &a[i][k] , &t[i][j]);
		}
	}
	for(int i = 1 ; i <= q ; ++ i)
	{
		int x , y;
		scanf("%d%d" , &x , &y);
		
		int ans = w[x] + t[x][x] + t[x][y] + w[y];
		printf("%d\n" , ans);
	}
	
	return 0;
}
