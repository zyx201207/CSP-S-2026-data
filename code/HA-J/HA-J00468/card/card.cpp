#include<bits/stdc++.h>
using namespace std;
int a[500001];
int t[300001];
int d[300001];
int v[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			t[a[j]]++;
			if(t[a[j]] > 1)
			{
				for(int k = d[a[j]];k < j;k++)
				{
					t[a[k]]--;
				}
			}
			d[a[j]] = i;
		}
		for(int j = 1;j <= m;j++)
		{
			cout << t[a[j]];
			if(t[a[j] == 1])
			{
				v[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		if(v[a[i]] > 0)
		{
			cout << v[a[i]] << " ";
		}
	}
	return 0;
}
