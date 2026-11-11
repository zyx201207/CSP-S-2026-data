#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int d[500010];
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n-i;++j)
		{
			d[j]=0;
		}
		
		d[i]=a[i];
		for(int j=1;j<=i;++j)
		{
			if(d[j]==d[i])
			{
				for(int x=j;x<=i;++x)
				{
					d[x]=0;
				}
				break;
			}
		}
		
		for(int j=1;j<=n-i;++j)
		{
			b[d[j]]++;
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}