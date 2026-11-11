#include<bits/stdc++.h>
using namespace std;
int n,m,now,p,ans;
bool a[200005][35],b[35];
int ve[35][200005];
int t[35];
int fun(int x)
{
	int cnt;
	for(int i = 0;i <= t[i];i++)
	{
		if(a[ve[x][i]][x])cnt++;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> now;
		p = 0;
		while(now)
		{
			if(now&1)
			{
				a[i][p] = 1;
				ve[p][t[i]]=i;
				t[i]++;
			}	
			p++,now>>=1;
		}
	}
	for(int i = 30;i >= 0;i--)
	{
		if(fun(i) >= m)
		{
			b[i] = 1;
			ans += (1ll<<i);
			for(int j = 1;j <= n;j++)
			{
				if(a[j][i] == 0)
				{
					for(int k = 0;k <= 30;k++)
					{
						a[j][k] = 0;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
