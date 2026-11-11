#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],z[5001],b[5001],zhi=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		zhi=i;
		for(int j=i;j<n;j++)
		{
			for(int q=j+1;q<n;q++)
			{
				if(a[q]==a[j])
				{
					zhi=q;
				}
			}
		}
		for(int j=zhi;j<n;j++)
		{
			b[a[j]]+=1;
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
