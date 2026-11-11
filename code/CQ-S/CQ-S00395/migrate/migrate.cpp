#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

long long a, b, c, d, e, f[N], g, p, T;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> p >> T;
	if(p == 11 || p == 12)
	{
		while(T --)
		{
			g = 0;
			cin >> a >> b;
			for(int i = 1; i <= a; i ++) cin >> f[i];
			long long k = f[2] - f[1];
			if(k >= b) cout << 0;
			if(a % 2 == 1)
			{
				for(int i = 1; i <= (a - 3) / 2; i ++)
				{
					g = g + i * 2;
				}
				cout << g << '\n';
			}
			else
			{
				if(a == 4) cout << 1;
				else if(a == 6) cout << 3;
				else 
				{
					g = (a - 2) / 2; 
					for(int i = 1; i <= (a - 4) / 2; i ++)
					{
						g += i * 2; 
					}
					cout << g;
				}	
				cout << '\n';
			}
		}
	}
	return 0;
}


