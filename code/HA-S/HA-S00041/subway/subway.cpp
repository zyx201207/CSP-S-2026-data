#include<bits/stdc++.h>

#define int long long 

using namespace std;

int c, n, m, d, q;
int w[N], a[N][N], t[N][N];
int k[N];
int x, y; 
signed main()
{
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{ 
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		cin >> x >> y;
		
	}
	return 0;
}//  
/*

               ,
             _/((
    _.---. .'   `\
  .'      `     ^ T=
 /     \       .--'
|      /       )'-.
; ,   <__..-(   '-.)
 \ \-.__)    ``--._)
  '.'-.__.-.¦¸¦¸¦¸¦¸
    '-...-'

¨Å¨Æ¨Ç¨È¨É¨Ê¨Ë¨Ì
¨Ú¨Å¨Ø¨É¨ç¨è¨é¨Í¨Î¨Ï¨Ð¨Ñ¨Ò¨Ô¨Õ¨Ö¨×
*/
