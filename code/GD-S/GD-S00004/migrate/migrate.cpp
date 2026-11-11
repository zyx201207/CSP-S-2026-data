#include <bits/stdc++.h>
using namespace std;
struct S
{
	long long duan = 1e18 + 5,cnt;
}v[5005][5005];
long long c,t,n,d,sum,a[5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld",&c);
	scanf("%lld",&t);
	for(int k = 1;k <= t;k++)
	{
		sum = 0;
		scanf("%lld",&n);
		scanf("%lld",&d);
		for(int i = 1;i <= n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(v[i][j].duan == a[j] - a[i])
				{
					v[i][j].cnt++;
				}
				else if(v[i][j].duan > a[j] - a[i])
				{
					v[i][j].cnt = 1;
					v[i][j].duan = a[j] - a[i];
				}
			}
		}
		for(int k = 1;k <= n;k++)
		{
			for(int i = 1;i < k;i++)
			{
				for(int j = k + 1;j <= n;j++)
				{
					if(v[i][j].duan == v[i][k].duan + v[k][j].duan)
					{
						v[i][j].cnt++;
					}
					else if(v[i][j].duan > v[i][k].duan + v[k][j].duan)
					{
						v[i][j].duan = v[i][k].duan + v[k][j].duan;
						v[i][j].cnt = 1;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(v[i][j].cnt == 2)
				{
					sum++;
				}
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
