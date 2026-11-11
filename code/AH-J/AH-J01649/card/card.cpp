#include<bits/stdc++.h>
using  namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005],b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;i<=n;i++)
		{
			if(a[i]==a[j])
			{
				for(int k=1;k<=j;k++)
				{
					a[k]=0;
				}
			}
			b[i]=a[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
