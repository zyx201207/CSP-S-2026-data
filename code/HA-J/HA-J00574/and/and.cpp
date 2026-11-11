#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200010],maxx=-9999,b[200010],x,minn=9999;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		maxx=-9999;
		for(int j=1;j<=n;j++)
		{
			if(a[j]>maxx) 
			{
				maxx=a[j];
				b[i]=a[j];
				x=j;
			}
		}
		a[x]=0;
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]<minn) minn=b[i];	
	}
	cout<<minn;
return 0;
}
