#include <bits/stdc++.h>
using namespace std;
int c;
long long n, m, d, q;
long long w[100005];
long long k[100005], a[5005][5005], t[5005][5005];
vector <long long> line[5005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			line[i].push_back(a[i][j]);
		}
	}	
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		vector <long long> inxlines;
		vector <long long> inylines;
		vector <long long> linex, liney;
		for (int i = 1; i <= n; i++)
		{
			for (unsigned int j = 0; j < line[i].size(); j++)
			{
				if (x == line[i][j]) 
				{
					inxlines.push_back(i);
					linex.push_back(j);
				}
				if (y == line[i][j]) 
				{
					inylines.push_back(i);
					liney.push_back(j);
				}
			}	
		}
		bool flag = false;
		for (unsigned int i = 0; i < inxlines.size(); i++) 
		{
			for (unsigned int j = 0 ; j < inylines.size(); j++)
			{
				if (inxlines[i] == inylines[j])
				{
					cout << w[x] + w[y] + t[inxlines[i]][i] + t[inylines[j]][j];
					flag = true;
				}
			}
		}
		if (flag == true) continue;
		vector <long long> transfer;
		for (unsigned int i = 0; i < inxlines.size(); i++)
		{
			for (unsigned int j = 0; j < inylines.size(); i++)
			{
				for (int k = 1; k <= 400; k++)
				{
					for (int l = 1; l <= 400; l++)
					{
						if (a[i][k] == a[j][l]) transfer.push_back(a[i][k]);
					}
				}
			}
		}	
		long long mnd = LLONG_MAX;
		for (int i = 0; i < transfer.size(); i++)
		{
			
		}
	}
	return 0;
}
