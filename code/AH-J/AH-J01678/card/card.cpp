#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],b[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	int x=1;
	while(x<=n)
	{
		for(int i=1;i<=n;i++)
			a[i]=c[i];
		for(int i=x;i<=n;i++)
		{	
			for(int j=i+1;j<=n;j++)
			{	
				if(a[i]==a[j])
				{
					for(int c=i;c<j;c++)
						a[c]=-1;
					i=j;
				}
			}
		}
		for(int i=x;i<=n;i++)
		{	
			if(a[i]>0)		
				b[a[i]]++;				
		}
		x++;
	}
	for(int i=1;i<=m;i++)
	{	
		cout<<b[i]<<' ';
	}
	return 0;
}
