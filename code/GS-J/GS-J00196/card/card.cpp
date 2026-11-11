#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m,a[100005],t=1,b[100005],c[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		t=1;
		for(int j=i+1;j<=n;j++)
		{
			a[t]=b[j];
			t++;
		}
		for(int k=1;k<=n;k++)
		{
			for(int y=k+1;y<=n;y++)
			{
				if(a[y]==a[k])
				{
					for(int x=k;x<y;x++)
					{
						a[x]=0;
					}
				}
			}
		}
	
		for(int j=1;j<=n;j++)
		{
			c[a[j]]++;
		}
		for(int j=i;j<=n;j++)
		{
			a[j]=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<c[j]<<" ";
	}
	return 0;
}
