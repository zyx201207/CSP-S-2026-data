#include<bits/stdc++.h>
using namespace std;

int a[500005],b[500005],c[500005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int d=0,n,m;
	//dÊÇÎ»Êý 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			d++;
			a[d]=b[d];
			for(int k=1;k<d;k++)
			{
				if(a[k]==a[d]&&k!=d)
				{
					d=k;
				}
			}
		}
		for(int k=i;k<=d;k++)
		{
			c[a[k]]++;
		}
		d=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	
	return 0;
}
