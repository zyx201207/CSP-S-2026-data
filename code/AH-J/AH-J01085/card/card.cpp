#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[300005],c[500005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,i,j,k,t=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i+1])
		{
			t=1;
		}
		b[a[i]]=i;
	}
	if(t==0)
	{
		for(i=1;i<=m;i++)
		{
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int s=0;
		for(j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				s++;
				b[a[j]]=s;
				c[s]=a[j];
				
			}
			else
			{
				int t=b[a[j]];
				for(k=t;k<=s;k++)
				{
					b[c[k]]=0;
				}
				s=t;
				b[a[j]]=t;
			}
		}
		for(j=1;j<=s;j++)
		{
			d[c[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}		
}
