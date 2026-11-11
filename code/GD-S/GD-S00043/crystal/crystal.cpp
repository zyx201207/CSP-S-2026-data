#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n = 0, m = 0,h = 0,ans = 1;
	cin >> n >> m;
	int a[n];
	int t = m;
	for (int i = 0; i < n ; i++)
	{
		cin>>a[i];
	}
	for(int j = 0; j < n;j++)
	{
		int te = a[j];
		h = 0;
		m = t;
		for(int k = 0; k < n;k++)
		{
			if(a[k] == te)
			{
				h = h + 1;
				if(h > ans)
				{
					ans = h;
				}
				continue;
			}
			else if (a[k] > te || m <= 0 || k == j) continue;
			else 
			{
				m = m - (te - a[k]);
				h = h + 1;
				if(h > ans)
				{
					ans = h;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 

