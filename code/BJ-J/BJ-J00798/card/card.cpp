#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[500005],last[300005],cha[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		c[i] = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		if(last[a[i]] > 0)
		{
			c[last[a[i]]] -= cha[a[i]];
			c[i] += cha[a[i]];
		}
		last[a[i]] = i;
		cha[a[i]] = i;
	}
	int p = 0;
	for(int i = 1;i <= n;i++)
	{
		p += c[i];
		ans[a[i]] += p;
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}

