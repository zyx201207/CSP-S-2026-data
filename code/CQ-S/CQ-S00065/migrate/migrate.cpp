#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000005],num,minn=1000000,sum=0;
void dfs(int u,int v,int step)
{
	if (u == v)
	{
		if (step < minn)
		{
			minn = step;
			sum=0;
		}
		else if (step == minn)
		{
			sum++;
		}
		return ;
	}
	for (int l=u+1; l <= v; l++)
	{
		if (x[l]-x[u] <= d)
		{
			dfs(l,v,step+1);
		}
	}
	return ;
}
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int o=1; o <= t; o++)
	{
		cin >> n >> d;
		for (int i=1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i=1; i <= n-1; i++)
		{
			for (int j=i+1; j <= n; j++)
			{
				minn = 1000000;
				sum = 0;
				dfs(i,j,0);
				if (sum == 2)
				{
					num++;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
