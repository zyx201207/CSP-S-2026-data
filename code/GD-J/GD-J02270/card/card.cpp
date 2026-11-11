#include <iostream>
#include <stack>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int cnt[M];
bool vis[M];
int a[N];
stack<int> stk;
int lst[M];
int cnta[M];
int d[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool flag = 1;
	for (int i = 1; i < n; i++) if (a[i] > a[i+1])
	{
		flag = 0;
		break;
	}
	if (flag)
	{
		for (int i = 1; i <= n; i++) if (a[i] != a[i+1]) cout << i << " ";
		return 0;
	}
	if (n <= 5000)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++) vis[a[j]] = 0;
			for (int j = i; j <= n; j++)
			{
				if (vis[a[j]])
				{
					while (!stk.empty() && stk.top() != a[j])
					{
						vis[stk.top()] = 0;
						stk.pop();
					}
					if (!stk.empty() && stk.top() == a[j]) stk.pop();
					stk.push(a[j]);
				}
				else
				{
					vis[a[j]] = 1;
					stk.push(a[j]);
				}
			}
			while (!stk.empty())
			{
				cnt[stk.top()]++;
				stk.pop();
			}
		}
		for (int i = 1; i <= m-1; i++) cout << cnt[i] << " ";
		cout << cnt[m];
		return 0;
	}
	if (m == 1)
	{
		cout << n;
		return 0;
	}
	if (m == 2)
	{
		int lst1 = n, lst2 = n;
		while (lst1 > 0 && a[lst1] == 2) lst1--;
		while (lst2 > 0 && a[lst2] == 1) lst2--;
		if (lst1 < lst2)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 1) cnt[1]++,cnt[2]++;
				else cnt[2]++;
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 2) cnt[1]++,cnt[2]++;
				else cnt[1]++;
			}
		}
		cout << cnt[1] << " " << cnt[2];
		return 0;
	}
	for (int i = n; i >= 1; i--)
	{
		if (!lst[a[i]]) lst[a[i]] = i;
		cnta[a[i]]++;
	}
	for (int i = 1; i <= m; i++) d[lst[i]] += cnta[i];
	for (int i = 1; i <= n; i++) d[i] += d[i-1];
	for (int i = 1; i <= m; i++) cout << d[lst[i]] << " ";
	return 0;
}

