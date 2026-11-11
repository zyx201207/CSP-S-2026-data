#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i]; 
	}
	for(int i=0;i<n;i++)
	{
		int num=n-i;
		for(int j=0;j<num;j++)
		{
			if(a[i]==a[j])
			{
				for(int z=i;z<j;z++)
				{
					a[z]=0;
				}
			}
		}
		for(int j=0;j<num;j++)
		{
			for(int z=0;z<m;z++)
			{
				if(a[j]==z)
				{
					b[z]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout << b[i] << " ";
	}
}
