#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k,n,m,top,sum;
	cin>>n>>m;
	if(n>500)
	{
		for(i=1;i<=n;i++)
			cout<<i<<" ";
		return 0;
	}
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		top=1;
		for(j=i;j<=n;j++)
		{
			sum=-1;
			for(k=1;k<=top;k++)
			{
				if(c[k]==a[j])
				{
					sum=k;
					break;
				}
			}
			if(sum!=-1)
			{
				for(k=sum;k<=m;k++)
					c[k]=0;
				top=sum;
			}
			c[++top]=a[j];
		}
		for(j=1;j<=m;j++)
			b[c[j]]++;
	}
	for(i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
