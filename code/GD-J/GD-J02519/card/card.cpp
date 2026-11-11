#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int d[300005],a_cnt[500005],cnt,ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int k = 1;
	while(k <= n)
	{
		for(int i = 1;i <= m;i++)
			d[i] = 0;
		for(int i = 1;i <= n;i++)
			a_cnt[i] = 0;
		cnt = 0;
		for(int i = k;i <= n;i++)
		{
			if(d[a[i]] == 0)
			{
				cnt++;
				a_cnt[cnt] = a[i];
				d[a[i]] = cnt;
			}
			else
			{
				for(int j = d[a[i]]+1;j <= cnt;j++)
				{
					d[a_cnt[j]] = 0;
					a_cnt[j] = 0;
				}
			}
		}
		for(int i = 1;i <= cnt;i++)
			ans[a_cnt[i]]++;
		k++;
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
	return 0;
}
