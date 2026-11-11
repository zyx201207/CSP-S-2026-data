#include <iostream>
#include <vector>
#include <chrono>

using std::cin;
using std::cout;

int c, n, m, d, q;

int g_to_m[505];

const long long inf = 1e18;

std::vector <std::pair <long long, long long> > this_line;

long long dp[505][505];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> m >> n >> d >> q;
	
	for(long long i = 1; i <= n; i++)
	{
		cin >> g_to_m[i];
		
		for(long long j = 1; j <= n; j++)
		{
			dp[i][j] = inf;
		}
	}
	
	for(long long i = 1; i <= m; i++)
	{
		long long k;
		
		cin >> k;
		
		this_line.clear();
		
		while(k--)
		{
			long long pos, time;
			
			cin >> pos >> time;
			
			for(std::pair <long long, long long> p : this_line)
			{
				dp[p.first][pos] = std::min(dp[p.first][pos], time + p.second);
				
				dp[pos][p.first] = std::min(dp[pos][p.first], time + p.second);
			}
			
			this_line.push_back({pos, time});
		}
	}
	
	for(long long k = 1; k <= n; k++)
	{
		for(long long i = 1; i <= n; i++)
		{
			for(long long j = 1; j <= n; j++)
			{
				dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	for(long long i = 1; i <= q; i++)
	{
		long long start, end;
		
		cin >> start >> end;
		
		cout << dp[start][end] + g_to_m[start] + g_to_m[end] << '\n';
	}
}















