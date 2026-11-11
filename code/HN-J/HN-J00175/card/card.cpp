#include <bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;
const int N = 2e5+10;
int n,m,w,t,a[N],k,z,b[N],c[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i-1] < a[i])
		{
			k++;
		}
	}
	if (k == n)
	{
		for (int i = 1;i <= m;i++)
		{
			cout << i << " ";
		}
		return 0;
	}
	z = 0;
	for (int k = 1;k <= n;k++)
	{
		memset(b,0,sizeof b);
		for (int j = k;j <= n;j++)
		{
			if (b[a[j]] > 1)
			{
				memset(b,0,sizeof b);
				break;
			}
			b[a[j]]++;
		}
		for (int i = 1;i <= n;i++)
		{
			c[b[i]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
