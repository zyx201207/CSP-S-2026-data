#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005];
	bool q[300005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		q[i] = false;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if (q[j] != true)
			{
				q[j] = true;
			}
			else
			{
				for (int k = 1;k <= m;k++)
		        {
			        q[k] = false;
		        }
			}
		}
		for (int k = 1;k <= m;k++)
		{
			if (q[k] == true)
			{
				b[k]++;
			}
			q[k] = false;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
