#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m, a[500001] = {}, ans[m + 2] = {};
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		int now_back[n-i+5] = {};
		now_back[i] = a[i];
		int count_back = i;
		
		for (int j = i; j <= n; j++)
		{
			count_back++;
			for (int k = i; k < count_back; k++)
			{
				if (now_back[k] == a[j])
				{
					for (int q = k; q < count_back; q++)
					{
						now_back[q] = 0;
						count_back--;
					}
					break;
				}
			}
			now_back[count_back] = a[j];
		}		
		
		for (int j = i; j <= count_back; j++)
		{
			ans[now_back[j]] ++; 
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	
	cout << "\n";
	return 0;
} 
 
    
