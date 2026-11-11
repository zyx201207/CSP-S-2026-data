#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005],b[1000005];
int main() {
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		for(int j=1;i<=i;i++)
		{
			if(a[j]==a[i]])
			{
				for(int k=j;k<=i;k++)
				{
					a[k]==0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[i]==i)
		{
			b[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i];
	}
	return 0;
}
