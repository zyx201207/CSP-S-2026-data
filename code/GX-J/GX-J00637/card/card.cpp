#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout	);
	int n,m;
	cin>>n>>m;
    int a[m],b[m],c[m],d[m];	
    for(int i=1;i<=n;i++)
    {	
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(c[i]<=m)
			{
				d[m-c[i]]==1;
				if(d[i]==1) b[m]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
}
