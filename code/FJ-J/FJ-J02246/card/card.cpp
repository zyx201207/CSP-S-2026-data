#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500005],las[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		las[a[i]]=i;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			ans[a[j]]++;
			j=las[a[j]];
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
