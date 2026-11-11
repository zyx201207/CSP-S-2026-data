#include<bits/stdc++.h>

using namespace std;
int k,n,d,talto,ans,end,as = 100000000;
long long a[305];
short b[305][305];
bool c[305];
void dfs1(int set)
{
	for(int i = set + 1;i < n;i++)
	{
		if(a[i] - a[set] <= d)
		{
			c[i] = 1;
			if(!c[i])dfs1(i);
		}
		else
		{
			return ;
		}
	}
}
void dfs(int set,int step)
{
	if(set >= end)
	{
		if(set == end)
		{
			if(as > step)
			{
				as = step;
				talto = 0;
			}
			else
			{
				talto++;
			}
		}
		return ;
	}
	for(int i = set + 1;i < n;i++)
	{
		
		if(a[i] - a[set] <= d)
		{
			
			dfs(i,step + 1);
		}
		else
		{
			return ;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> k >> k;
	while(k--)
	{
		cin >> n >> d;
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		if(n <= 300)
		{
			dfs1(0);
			for(int i = 0;i < n;i++)
			{
				if(c[i])
				{
					for (int j = i + 1;j < n;j++)
					{
						if(c[j])
						{
							end = j;
							dfs(i,0);
							if(talto == 2)
							{
								ans++;
								talto = 0;
								as = 100000000;
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
		memset (c,0,sizeof c);
		ans = 0;
	}
	return 0;	
}
