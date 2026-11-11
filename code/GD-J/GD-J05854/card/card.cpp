#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n, m, a[200005], flag[200005], cnt[200005];
stack<int> s;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int j = 1; j <= n; j++)
	{
		memset(flag, 0, sizeof(flag));
		for (int i = j; i <= n; i++)
		{
			if (flag[a[i]] == 1)
			{
				while (!s.empty())
				{
					int tt = s.top();
					if (tt == a[i])
					{
						s.pop();
						break;
					}
					flag[tt] = 0;
					s.pop();
				}
			}
			s.push(a[i]);
			flag[a[i]] = 1;
		}
		while (!s.empty())
		{
			cnt[s.top()]++;
			//cout << s.top() << ' ';
			s.pop();
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << cnt[i] << ' ';
	}
	return 0;
}
