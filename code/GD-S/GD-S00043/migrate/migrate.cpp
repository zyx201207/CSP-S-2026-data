#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c = 0, t = 0;
	cin >> c >> t;
	int p[t];
	for(int g = 0; g < t;g++)
	{
		int n = 1, d = 1;
		cin >> n >> d;
		int is[n];
		p[g]=0;
		for (int i = 0;i < n;i++)
		{
			cin>>is[i];
		}
		for (int u = 1;u<=n;u++)
		{
			for (int v = 1;v<=n;v++)
			{
				if((is[v]-is[u])%d==0 || u>v || is[v]-is[u] > d ) continue;
				int minf = (is[v]-is[u])/d + 1;
				for(int i = d;i>0;i--)
				{
					if((is[v]-is[u])/i == minf) p[g] += 1;
				}
			}
		}
	}
	for (int i = 0;i < t; i++)
	{
		cout << p[i] -t + 1 << endl;
	}
	return 0;
 } 
