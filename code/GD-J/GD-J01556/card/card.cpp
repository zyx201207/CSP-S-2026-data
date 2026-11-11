#include<bits/stdc++.h>
using namespace std ;
int n,m,a[500005],b[500005],k,c[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			
			for(int o=1;o<=k;o++)
			if(b[o]==a[j])
			{
				k=o-1;
				break;
			}
			b[++k]=a[j];
		}
		for(int j=1;j<=m;j++)
		for(int o=1;o<=k;o++)
		{	
			{
				if(b[o]==j)c[j]++;
			}
		}
		/*cout<<k<<"\n";
		for(int j=1;j<=k;j++)cout<<b[j]<<" ";
		cout<<"\n";*/
		memset(b,0,sizeof(b)); 
		k=0;
		
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
 } 
