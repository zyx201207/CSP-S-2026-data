#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[25][N];
int t[505][N];
int f[N][25];
int c,n,m,d,q; 
int h;
int dfs(int x, int y)
{
	
}
void min(int x,int y)
{
	dfs(x,y);
	
}

int main()
{
	cin >> c >> n >> m >> d >> q;
	for ( int i = 1; i <= m; i++)
	{
		cin >> a[0][i];
	}
	for(int i = 1; i <= n;i++)
	{
		int b = 0;
		cin >> b;
		for(int j = 1; j <= b;j++)
		{
			int x,y;
			cin >> x >> y;
			a[i][x] = y;
			t[i][j] = x;
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int x = 0,y = 0;
		cin >> x >> y;
		min(x,y);
		
	}
	return 0;
}
