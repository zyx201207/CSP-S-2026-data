#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int k=1,f=1;
	for(;k<=n;k++)
	{
		f=k;
		for(int i=k;i<=n;i++)
		{
			int q=a[i];
			for(int j=1;j<=f+1;j++)
			{
				if(q==b[j]||j==f+1)
				{
					b[i]=q;
					f=i;
					break;
				}
			}
		}
		for(int i=1;i<=f;i++)
		{
			++c[b[i]];
		}
		for(int i=1;i<=n;i++)
		{
			b[i]=0;
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		cout<<c[i]-1<<' ';
	}
	cout<<c[m];
	return 0;
}
