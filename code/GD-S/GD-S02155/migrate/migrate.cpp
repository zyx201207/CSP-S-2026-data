#include<bits/stdc++.h>

using namespace std;
int c, t;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		int n, ans = 0;
		long long d;
		cin >> n >> d;
		vector<long long> a(n+1);
		vector<vector<int>> step(n+1, vector<int>(n+1, -1));
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for(int i = 1; i < n; i++)
		{
			step[i][i] = 0;
			int l = i;
			for(int j = i+1; j <= n; j++)
			{
				if(a[j]-a[l]<=d)
				{
					step[i][j] = step[i][l]+1;
					if(a[j]-a[l]==d)
					{
						l = j;
					}
				}
				else if(a[j]-a[j-1]<=d)
				{
					step[i][j] = step[i][j-1]+1;
					l = j-1;
				}
				else
				{
					break;
				}
			}
		}
		for(int i = 1; i < n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				if(step[i][j]==1)
				{
					continue;
				}
				else if(step[i][j]==-1)
				{
					break;
				}
				int cnt = 0;
				for(int k = i+1; k < j; k++)
				{
					if(step[i][j]==step[i][k]+step[k][j])
					{
						cnt++;
						if(cnt>2)
						{
							break;
						}
					}
				}
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
