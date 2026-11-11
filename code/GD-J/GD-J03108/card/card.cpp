#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], sum[N];
unordered_map<int, int> g, v;
int main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int r = 1; r <= n; r++)
	{
			g.clear();
			v.clear();
			int pos = 0;
			//cout << n - r << ' ';
			//for (int i = 1; i <= 4; i++)cout << g[i] << ' ' ;
			//cout << "|||||||||"; 
			for (int i = r; i <= n; i++)
			{
				bool flag = 0;
				for (int j = 1; j <= pos; j++)
				{
					if (g[j] == a[i])
					{
						flag = 1;
						break;
					} 
				}
				if (flag == 0)
				{
					//cout << '*';
					pos++;
					g[pos] = a[i];
				}
				else
				{
					if (a[i] == 0)continue;
					//cout << r << '|';
					v.clear();
					int p = 0;
					for (int j = 1; j <= pos; j++)
					{
						if (g[j] == a[i])
						{
							//cout << g[j] << ' ' << j << ' ' << i << '|';
							p = j;
							break;
						}
					}
					
					for (int j = 1; j <= p; j++)
					{
						v[j] = a[j];
					}
					pos = p;
					g.clear();
					g = v;
				}
				/*
					for (int j = 1; j <= pos; j++)
					{
						cout << g[j] << ' ';
					}
					cout << '\n';		
				
				*/
		
			}
			for (int i = 1; i <= pos; i++)
			{
				sum[g[i]]++;
				//cout << g[i] << ' ';
			}	
			//cout << '\n';
	}
	for (int i = 1; i <= m; i++)
	{
		cout << sum[i] << ' ';
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
