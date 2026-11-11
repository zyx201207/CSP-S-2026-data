#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,len,s,ans,minn;
struct node{int a;char c;}a[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].a >> a[i].c;
		len += a[i].a;
	}
	for (int i = 1;i <= n;i++)
	{
		if (s + a[i].a > len / 2)
		{
			int k = i,l = a[i].a - len / 2 + s - len % 2,d = 0;
			if (s == len / 2) k--;
			while (1)
			{
				if (a[k].c != a[i].c) ans += min(l,(k == i? len / 2 - s:a[k].a));
				if (l >= (k == i? len / 2 - s:a[k].a)) l -= (k == i? len / 2 - s:a[k].a),k--;
				else
				{
					d += l;
					break;
				}
			}
			for (int j = i + 1;j <= n;j++)
			{
				l = a[j].a;
				while (1)
				{
					if (a[k].c != a[j].c) ans += min(l,(k == i? len / 2 - s:a[k].a - d));
					if (l >= (k == i? len / 2 - s:a[k].a - d)) l -= ((k == i? len / 2 - s:a[k].a - d)),k--,d = 0;
					else
					{
						d += l;
						break;
					}
				}
			}
			break;
		}
		s += a[i].a;
	}
	s = 0,minn = ans,ans = 0;
	for (int i = n;i >= 1;i--)
	{
		if (s + a[i].a > len / 2)
		{
			int k = i,l = a[i].a - len / 2 + s - len % 2,d = 0;
			if (s == len / 2) k++;
			while (1)
			{
				if (a[k].c != a[i].c) ans += min(l,(k == i? len / 2 - s:a[k].a));
				if (l >= (k == i? len / 2 - s:a[k].a)) l -= (k == i? len / 2 - s:a[k].a),k++;
				else
				{
					d += l;
					break;
				}
			}
			for (int j = i - 1;j >= 1;j--)
			{
				l = a[j].a;
				while (1)
				{
					if (a[k].c != a[j].c) ans += min(l,(k == i? len / 2 - s:a[k].a - d));
					if (l >= (k == i? len / 2 - s:a[k].a - d)) l -= ((k == i? len / 2 - s:a[k].a - d)),k++,d = 0;
					else
					{
						d += l;
						break;
					}
				}
			}
			break;
		}
		s += a[i].a;
	}
	cout << min(minn,ans);
	return 0;
}
