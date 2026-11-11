#include<bits/stdc++.h>
using namespace std;
int a[300005],tong[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
	{ 
		int b[300005] = {};
		int cnt = 0;
		for(int j = i;j <= n;j++)
		{
			cnt++;
			b[cnt] = a[j];
			for(int k = 1;k < cnt;k++)
			{
				if(b[cnt] == b[k])
				{
					for(int x = k + 1;x <= cnt;x++)
					{
						b[x] = 0;
						cnt--;
					}
				}
			}
		}
		for(int j = 1;j <= cnt;j++)
			tong[b[j]]++;
	}
	for(int i = 1;i <= m;i++)
		cout << tong[i] << " ";
	return 0;
}
