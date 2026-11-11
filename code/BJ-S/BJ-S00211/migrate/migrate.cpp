#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> pll;

const int N = 5005;

int c , T;
ll n , d , a[N] , nxt[N] , res;
pll f[N][N];

int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> c >> T;
	if(c <= 10 || c == 13 || c == 14)
	{
		while(T --)
		{
			cin >> n >> d;
			for(int i = 1 ; i <= n ; ++ i)
				for(int j = 1 ; j <= n ; ++ j)
					f[i][j] = {0 , 0};
			res = 0;
			for(int i = 1 ; i <= n ; ++ i) cin >> a[i];
			for(int i = 1 ; i <= n ; ++ i)
			{
				int l = i , r = n;
				while(l < r)
				{
					int mid = l + r + 1 >> 1;
					if(a[mid] - a[i] <= d) l = mid;
					else r = mid - 1;
				}
				nxt[i] = l;
			}
			for(int i = n ; i ; -- i)
				for(int j = i - 1 ; j >= 1 ; -- j)
				{
					if(nxt[j] == j) continue;
					if(i <= nxt[j]) f[i][j] = {1 , 1};
					else
					{
						f[i][j].first = f[i][nxt[j]].first + 1;
						f[i][j].second = f[i][nxt[j]].second;
						if(nxt[j] - 1 >= j && (f[i][nxt[j] - 1].first + 1 == f[i][j].first)) f[i][j].second += f[i][nxt[j] - 1].second;
						if(nxt[j] - 2 >= j && (f[i][nxt[j] - 2].first + 1 == f[i][j].first)) f[i][j].second += f[i][nxt[j] - 2].second;
						f[i][j].second = min(f[i][j].second , 3);
					}
				}
			for(int i = 2 ; i <= n ; ++ i)
				for(int j = 1 ; j < i ; ++ j)
					res += (f[i][j].second == 2);
			
			cout << res << '\n';
		}
	}
	else
	{
		while(T --)
		{
			cout << "0\n";
		}
	}
	
	return 0;
}
