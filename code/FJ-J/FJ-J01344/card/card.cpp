#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> z(m + 1,0);
	vector<int> b(m + 1,0);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	stack<int> s;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;i++)
		{
			if(z[a[j]] != 1)
			{
				s.push(a[j]);
				z[a[j]] = 1;
			}
			else
			{
				while(!s.empty())
				{
					int x = s.top();
					if(x == a[j])
					{
						break;
					}
					s.pop();
					z[x] = 0;
				}
			}
		}
		while(!s.empty())
		{
			int x = s.top();
			b[x] += 1;
			s.pop();
		}
		for(int j = 1;j <= m;j++)
		{
			z[j] = 0;
		}
	}
	for(int i = 1;i <= m - 1;i++)
	{
		cout << b[i] << " ";
	}
	cout << b[m] << endl;
	return 0;
}
