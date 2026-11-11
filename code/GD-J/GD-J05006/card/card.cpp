#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int t=n;
		while (a[t]!=a[i])
		{
			b[a[t]]++;
			t--;
		}
		b[a[t]]++;
	}
	for (int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;	
}
