#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 2e5+5;
int ttt, n, m, d, q, c, r, ans;
int a[N][M], w[M], t[N][M], k[M];//int T[N][M], v[N][M];
//void dfs(int x,int y, long long Tm)
//{
//	if(T[x][y] == 2)
//	{
//		ans = Tm;
//		return ;
//	} 
//	v[x][y] = 1;
//	int j = 1;
//	while(x-j)
//	{
//			if(x-j != 0 && !v[x-j][y]) dfs(x-j, y, Tm+=t[x][y]+t[x-j][y]);
//			else break;
//			j ++;
//	}
//	j = 1;
//	while(x+j)
//	{
//			if(x+j != n && !v[x+j][y]) dfs(x-j, y, Tm+=t[x][y]+t[x+j][y]);
//			else break;
//			j ++;
//	}
//	j = 1;
//	while(y-j)
//	{
//			if(y-j != 0 && !v[x][y-j]) dfs(x, y-j, Tm);
//			else break;
//			j ++;
//	}
//	j = 1;
//	while(y+j)
//	{
//			if(y+j <= m && !v[x][y+j]) dfs(x, y+j, Tm);
//			else break;
//			j ++;
//	}
//}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> ttt >> n >> m >> d >> q;
    for (int i = 1 ; i <= m ; i ++) cin >> w[i];
    for (int i = 1 ; i <= n ; i ++)
    {
    	cin >> k[i];
    	for (int j = 1 ; j <= k[i] ; j ++)
    	{
    		cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1 ; i <= q ; i ++)
	{
		cin >> c >> r;
//		int e=0, f=0, g=0;
//		for(int j = 1 ; j <= n ; j ++)
//	    {	
//		    for(int l = 1 ; l < k[j] ; l ++)
//		    {
//		    	T[j][l] = 1;
//		    	if (a[j][l] == c)
//		    	{
//		    		e = j; f = l;
//				}
//		    	if (a[j][l] == r)
//		    	{
//		    		g = 1;
//		    		T[j][l] = 2;
//				}
//		    	if (e && f && g) 
//				{
//					dfs(e, f, 0);
//				}
//	    	}
//		}
		cout << ans + w[c] + w[r] << "\n";
	}
	return 0;
}

