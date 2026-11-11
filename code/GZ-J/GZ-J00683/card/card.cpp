//GZ-J00683 遵义市第十二中学 兰至立 
#include<bits/stdc++.h>
using namespace std;
int m,n,a[100050]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	int b[100005]={0},c[100005]={0},d[100005]={0},p=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=m;l++)
	{
	for(int i=1;i<=m;i++)
	{
		if(b[a[l]])
		{
			for(int j=c[a[i]];j<=i;j++)
			{
				b[a[j]]=0;
				c[a[j]]=0;
			}
			b[a[i]]++;
			c[a[i]]=i;
		}
		else
		{
			b[a[i]]++;
			c[a[i]]=i;
		}
	}
	for(int j=1;j<=m;j++)
		{
			if(b[j])
			{
				d[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
