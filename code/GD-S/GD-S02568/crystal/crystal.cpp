#include <bits/stdc++.h> 
using namespace std;
int a[500005];
int b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout); 
	int n,m;
	int maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]<=a[j])
			{
				break;
			}
			b[i]+=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=m && b[i]>0)
		{
			int num=m;
			int x=1;
			for(int j=1;j<i;j++)
			{
				num-=a[i]-a[j];
				if(num<0)
				{
					continue;
				}
				x++;
			}
			maxx=max(maxx,x);
		}
	}
	cout<<maxx;
	return 0;
}
