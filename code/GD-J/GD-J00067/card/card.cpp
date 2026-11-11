#include<bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 10;
const int maxm = 3e5 + 10;

int n, m, a[maxn], b[maxn], c[maxn];
int p, pos[maxm], res[maxm];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	
	for (int x = 1;x <= n;x++)
	{
		p = 0;
		
		memset(b, 0, sizeof(b));
		memset(pos, 0, sizeof(pos));
		for (int j = x;j <= n;j++)
		{
			b[j - x + 1] = a[j];
		}
		
		for (int i = 1;i <= n - x + 1;i++)
		{
			cout << b[i] << " ";
		}cout << '\n';
		
		for (int i = 1;i <= n - x + 1;i++)
		{
			p++;
			c[p] = b[i];
			
			if (pos[c[p]] != 0)
			{
				p = pos[c[p]];
			}
			else
			{
				pos[c[p]] = p;
			}
		}
		
		for (int i = 1;i <= p;i++)
		{
			res[b[i]]++;
		}
		
	}
	
	for (int i = 1;i <= m;i++)
	{
		cout << res[i] << " ";
	}
	
	return 0;
}
