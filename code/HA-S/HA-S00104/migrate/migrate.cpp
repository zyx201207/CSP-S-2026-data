#include <bits/stdc++.h>
using namespace std;
int c,t;
const int X=2*1e6+7;
int x[X];
bool ws(int d,int c)
{
	int y = c%d;
	
	if (y%2==1)
	{
		return true;
	}
	return false;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		int num=1;
		int n,d;
		cin >> n >> d;
		for (int j = 1;j <= n;j++)
		{
			cin >> x[j];
		}
		for (int j = 3;j < n;j++)
		{
			for (int u=j;u < n;u++)
			{
				int c=x[u]-x[j];
			    if(c%d==0)
		        {
			        continue;
		        }
		        else
		        {
			        if(ws(d,c))
			        {
				        num++;
			        }
		        }
			}
		}
		cout << num << endl;
	}
	return 0;
}
