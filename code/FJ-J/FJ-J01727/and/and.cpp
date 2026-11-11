#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int nums[MAXN];
int debug = 0;
int ans = -1;
int n, m;

void dfs(int depth, int& maxn, int i)
{
	for (int j = i + 1; j <= n; j++)
	{
		maxn = max(maxn, nums[i] & nums[j]);
		
//		cerr << depth << "_____" << maxn << endl;
//		cerr << (depth < m) << "_" << m << endl;

		if (depth < m)
		{
			dfs(depth + 1, maxn, j);
			
//			cerr << depth << "--" << maxn << endl;

		}
	}	
	return ;
} 

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	freopen("and.err", "w", stderr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	cin >> nums[i];
	
//	cerr << n << " " << m << endl;

	if (n <= 3000)
	{
			
//		cerr << "...." << endl;

		for (int i = 1; i <= n; i++)
		{
			
//			cerr << "!" << i << endl;

			dfs(1, ans, i);
		}	
		cout << ans << endl;
	}
	else if (m == n - 1)
	{
		int sum = nums[1];
		for (int i = 2; i <= n; i++)
		{
			sum &= nums[i];
		}
		
		int maxn = -1;
		for (int i = 1; i <= n; i++)
		{
			maxn = max(maxn, sum ^ nums[i]);
		}
		cout << maxn << endl;
	}
	return 0; 
}
