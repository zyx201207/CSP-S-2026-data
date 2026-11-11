#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],b[500005],book[100],c[500005];
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
		for(int j=1;j<=n;j++)
		{
			b[j]=a[j];
		}
		memset(book,0,sizeof book);
		for(int j=i;j<=n;j++)
		{
			if(book[b[j]]>0)
			{
				for(int k=book[b[j]];k<j;k++)
					b[k]=0;
			}
			book[b[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]>0)
			{
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
