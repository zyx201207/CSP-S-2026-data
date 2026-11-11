#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],ans[300005];
void you(int x)
{
	memset(b,0,sizeof(b));
	int j=0;
	for(int i=x;i<=n;i++)
	{
		
		if(b[a[i]]==0)
		{
			j++;
			b[a[i]]=j;
		}
		else
		{
			for(int k=1;k<=m;k++)
			{
				if(b[k]>b[a[i]]&&b[k]<=j)
				{
					b[k]=0;
				}
			}
			j=b[a[i]];
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]!=0)
		{
			ans[i]++;
		}
		
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f==0)
	{
		for(int i=1;i<=m;i++)
		{
			b[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1])
			{
				b[a[i]]++;
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			ans[i]=ans[i-1]+b[i];
		}
	}
	else if(n<=5000&&m<=3000)
	{
		for(int i=1;i<=n;i++)
		{
			you(i);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			ans[i]=b[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
//Trick||Treat!
