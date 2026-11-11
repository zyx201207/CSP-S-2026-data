#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	int w[m+1]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b[1000]={0};
		int jl=0;
		for(int j=i;j<=n;j++)
		{
			int c=1;
			for(int x=1;x<=jl;x++)
			{
				if(b[x]==a[j])
				{
					jl=x;
					c=0;
					break;
				}
			}
			if(c)
			{
				jl++;
				b[jl]=a[j];
			}
		}
		for(int i=1;i<=jl;i++)
		{
			w[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<w[i]<<" ";
	}
	return 0;
}
