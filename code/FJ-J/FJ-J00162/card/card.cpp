#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, a[500005], b[300005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	memset(b, 0, sizeof(b));
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	a[0] = 0;
	for(int i = 1;i <= n;i++)
	{ 
		vector<int> v;
		v.push_back(0);
		for(int j = i;j <= n;j++)
		{
			for(int k = v.size() - 1;k >= 1;k--)
			{
				if(a[j] == v[k])
				{
					while(!v.empty() && v.back() != v[k] && v.back() != 0)
					{
						v.pop_back();
					}
					if(!v.empty() && v.back() != 0)
						v.pop_back(); 
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int j = 1;j < v.size();j++)
		{
			b[v[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
