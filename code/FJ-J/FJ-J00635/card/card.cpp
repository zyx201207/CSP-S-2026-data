#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005],d[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int flag=0,cnt=1,a5=0,a6=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=a[i])
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		for(int i=1;i<=n;i++)
		{
			c[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			cout<<c[i]<<" ";
		}
	}
	else if(m==2 && n>=100) 
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				a5++;
			}
			else
			{
				a6++;
			}
		}
		cout<<a5<<" "<<a6;
	}
	else
	{
		int flag1=0;
		for(int i=1;i<=n;i++)
		{
			cnt=i;
			for(int j=i;j<=n;j++)
			{
				flag1=0;
				for(int k=1;k<cnt;k++)
				{
					if(c[k]==a[j])
					{
						cnt=k;
						flag1=1;
						break;
					}
				}
				if(flag1==1)
				{
					for(int a3=cnt;a3<=n;a3++)
					{
						c[a3]=0;
					}
				}
				c[cnt]=a[j];
				cnt++;
			}
			for(int a1=i;a1<=cnt;a1++)
			{
				d[c[a1]]++;
				c[a1]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<d[i]<<" ";
		}
	}
	return 0;
 } 
