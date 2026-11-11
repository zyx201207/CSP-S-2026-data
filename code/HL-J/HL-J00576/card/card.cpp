#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int a[N],res[M],n,m;
bool flag[M];
int s[N],p = 0;
void _push(int a)
{
	p++;
	s[p] = a;
}
void _pop()
{
	p--;
}
int _top()
{
	return s[p];
}
void _clear()
{
	p = 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if (flag[a[j]])
			{
				cout << a[j]; 
				while(!(_top() == a[j])) {flag[_top()] = 0;_pop();}           
				_pop();
				_push(a[j]);
			}
			else
			{
				_push(a[j]);
				flag[a[j]] = 1;
			}
		}
		for (int j = 1;j <= m;j++)
		{
			if (flag[j]) res[j]++;
		}
		_clear();
	}
	for (int i = 1;i <= m;i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}
