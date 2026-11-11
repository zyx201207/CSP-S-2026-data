#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],b[300010],c[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	for(int i=2;i<=m;i++)
	{
		b[i] += b[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
