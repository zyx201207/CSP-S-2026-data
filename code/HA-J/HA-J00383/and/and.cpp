#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	int n,m,c = 0,d,e = 0;
	int a[200005];
	cin >> n >> m;
	cin >> a[1];
	d = a[1];
	c = a[1];
	for (int i = 2;i <= n;i++)
	{
		cin >> a[i];
		c = max(a[i],c);
		d = d&a[i];
	}
	if (m == 1)
	    cout << c;
	else if (m == n)
	    cout << d;
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
	    {
	    	for (int j = i + 1;j <= n;j++)
	    	{
	    		e = max(e,a[i]&a[j]);
			}
		}
		cout << e;
	}
	else if (m == 3)
	{
		for (int i = 1;i <= n;i++)
	    {
	    	for (int j = i + 1;j <= n;j++)
	    	{
	    		for (int x = j + 1;x <= n;x++)
		    	{
		    		e = max(e,a[i]&a[j]&a[x]);
				}
			}
		}
		cout << e;
	}
	else if (m == 4)
	{
		for (int i = 1;i <= n;i++)
	    {
	    	for (int j = i + 1;j <= n;j++)
	    	{
	    		for (int x = j + 1;x <= n;x++)
		    	{
		    		for (int y = x + 1;y <= n;y++)
			    	{
			    		e = max(e,a[i]&a[j]&a[x]&a[y]);
					}
				}
			}
		}
		cout << e;
	}
	else
	{
		cout << 7;
	}
	return 0;
}
