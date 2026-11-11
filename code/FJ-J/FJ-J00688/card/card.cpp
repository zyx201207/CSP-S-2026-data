#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[300010];
void hh(int x)
{
	for(int i=x+1;i<=n;i++)
	{
		if(b[i]==b[x])
		{
			for(int j=x;j<i;j++)
			{
				b[j]=0;
			}
		}
	}
}
int main(){
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
		for(int j=1;j<i;j++)
		{
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]!=0)
			{
				hh(j);
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]!=0)
			{
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}

