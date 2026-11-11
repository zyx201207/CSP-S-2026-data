#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	string s;
	int n,m,f=0,gg=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1]) cout<<i<<" ";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			gg=0;
			for(int j=i;j<=n;j++)
			{
				f=0;
				for(int k=1;k<=gg;k++)
				{
					if(b[k]==a[j])
					{
						f=k;
						break;
					}
				}
				if(f==0)
				{
					gg=gg+1;
					b[gg]=a[j];
				}
				else
				{
					gg=f;
					b[gg]=a[j];
				}
			}
			for(int j=1;j<=gg;j++)
			{
				c[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	}
}
