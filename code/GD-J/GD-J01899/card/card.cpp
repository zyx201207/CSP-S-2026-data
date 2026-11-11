#include <bits/stdc++.h>
using namespace std;
int n , m , a[500010] , sum[300010],b[500010];
struct ppt
{
	int q , id;
}num[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int q = n;
	while(q--)
	{
		for(int i = 1;i <= n;i++)
			b[i] = 0;
		for(int i = 1;i <= m+1;i++)
		{
			num[a[i]].q = 0;
			num[a[i]].id = 0;
		}
		for(int i = n - q;i <= n;i++)
		{
			if(num[a[i]].q)
			{
				for(int j = num[a[i]].id;j <= i;j++)
				{
					b[j] = m + 1;
					num[a[j]].id = 0;
					num[a[j]].q = 0;
				}
					
			}
			b[i] = a[i];
			num[a[i]].q = 1;
			num[a[i]].id = i;
		}
		for(int i = n - q;i <= n;i++)
		{
			sum[b[i]] ++;
		}
	}
	for(int i = 1;i <= m;i++)
		cout << sum[i] << " ";
	return 0;
}
