#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], b[500005], c[500005], d[300005], p;

int main()
{
	freopen("card2.in", "r", stdin);  
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		if(b[a[i]] != 0)
		{
			c[b[a[i]] + 1] -= b[a[i]];
			c[i] += b[a[i]];
		}
		
		b[a[i]] = i;
	}
	
	for(int i = 1; i <= n; i++)
	{
		p += c[i];
		
		if(b[a[i]] <= i)
		{
			d[a[i]] += p;
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		cout << b[i] + d[i] << " ";
	}
	
	return 0;
}

