#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[500010],b[500010],c[300010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool flag=true;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]<a[i-1])
		{
			flag=false;
		} 
	}
	if(flag)
	{
		for(int i=1; i<=n; i++)
		{
			if(a[i]!=a[i-1] && i!=1)
			{
				cout << i << " ";
			}
		}
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			b[a[i]]=i;
		}
		for(int i=1; i<=n; i++)
		{
			int j=i;
			while(j<=n)
			{
				c[a[j]]++;
				j=b[a[j]];
				j++;
			}
		}
		for(int i=1; i<=m; i++)
		{
			cout << c[i] << " ";
		}
	}
	return 0;
}
