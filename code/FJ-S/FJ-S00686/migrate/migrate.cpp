#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],d,c,t;
int tiaoshu(int p,int q)
{
	int k;
	if(n%2==0)
	{
		k=n/2;
	}
	else
	{
		k=(n-1)/2;
	}
	if(a[q]-a[p]<=d || p+d==q-d || d>k)
	{
		return 1;
	}
	return tiaoshu(p,q-d)+tiaoshu(p+d,q);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(tiaoshu(i,j)==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
