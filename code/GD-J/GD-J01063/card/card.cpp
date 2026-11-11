#include<bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 3e5;
int n, m;
int a[N];
int vis[M];
int cnt[M];
bool A = 1;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] < a[i-1]) A = 0;
	}
	if(n <= 500 && m <= 200)
	{
		for(int h = 1; h <= n; h++)
		{
			stack<int> stk;
			for(int i = 1; i <= m; i++)
			{
				vis[i] = 0;
			}
			for(int i = h; i <= n ; i++)
			{
				if(!vis[a[i]])
				{
					vis[a[i]]++;
					stk.push(a[i]);
				}
				else
				{
					while(1)
					{
						int x = stk.top();
						if(x == a[i]) break;
						stk.pop();
						vis[x]--;
					}
				}
			}
			for(int j = 1; j <= m; j++)
			{
				if(vis[j])
				{
					cnt[j]++;
				}
			}
		}
		
		for(int i = 1; i <= m; i++)
		{
			cout << cnt[i] << ' ';
		}
	}
	else if(A)
	{
		for(int i = n; i >= 1; i--)
		{
			cnt[a[i]] = i;
		}
		
		for(int i = 1; i <= m; i++)
		{
			cout << n - cnt[i]+1 << ' ';
		}
	}
	return 0;
}
