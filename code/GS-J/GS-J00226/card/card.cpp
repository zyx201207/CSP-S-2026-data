#include <bits/stdc++.h>

using namespace std;

stack<int> r;

struct pk
{
	int tp, cc;
}a[123123];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;

	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i].tp;
		a[i].cc = 0;
	}
	for(int i = 0;i < n;i++)
	{
		bool val[123123] = {false};
		for(int j = i;j < n;j++)
		{
			if(!val[a[j].tp])
			{
				r.push(a[j].tp);
			}
			else if(val[a[j].tp] == true)
			{
				for(int k = j;;k--)
				{
					if(r.top() == a[j].tp)
					{
						break;
					}
					r.pop();
				}
			}
		}
		for(int j = i;j < n;j++)
		{
			if(r.top() == a[j].tp) a[j].cc++;
			r.pop();
	    }
	}
	for(int i = 0;i < m;i++)
	{
		cout << a[i].cc << ' ';
	}
	return 0;
}
