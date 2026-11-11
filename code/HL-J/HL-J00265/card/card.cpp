#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N] = {};
int b[N] = {};
int c[N] = {};
signed main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)  cin >> a[i];
	int m1 = m;
	while(m1--)
	{
		int i = m - m1;
		for(int j = i; j <= m; ++j)
		{
			b[j] = a[j];
			for(int k = 1; k <= j; ++k)
			{
				if(a[j] == b[k])
				{
					for(int l = k; l <= j; ++l)  b[l] = 0;
				}
			}
		}
		for(int j = 1; j <= m1; ++j)
		{
			if(b[j] == 0)  continue;
			else  c[b[j]]++;
		}
	}
	for(int i = 1; i <= m; ++i)
	{
		cout << c[b[i]] << " ";
	}
	return 0;
}	
