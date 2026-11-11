#include <iostream>
#include <cstring> 
using namespace std;

int n,m,a[500010],box[300010],c[500010],len,u;

bool check(int x)
{
	for (int i = 1;i <= len;i++)
	{
		if (c[i] == x)
		{
			return true;
		}
	}
	return false;
}

int ch(int x)
{
	for (int i = 1;i <= len;i++)
	{
		if (c[i] == x)
		{
			return i;
		}
	}
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
		memset(c,0,sizeof(c));
		len = 0;
		for (int j = i;j <= n;j++)
		{
			if (check(a[j]))
			{
				u = ch(a[j]);
				for (int k = u+1;k <= len;k++)
				{
					c[k] = 0;
				}
			}
			else
			{
				len += 1;
				c[len] = a[j];
			}
		}
		for (int j = 1;j <= len;j++)
		{
			box[c[j]] += 1;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << box[i] << " ";
	}
	return 0;
}
