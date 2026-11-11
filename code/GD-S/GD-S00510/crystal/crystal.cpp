#include <bits/stdc++.h>
using namespace std;
int n,m,sum=0;
long long a[500005],b[500005],c[500005];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			if (a[i]-a[j]>=0)
			{
				b[i]+=a[i]-a[j];
				c[i]++;
			}
		}
	}
	int j=0;
	for (int i=1;i<=n;i++)
	{
		if(b[i]<=m)
		{
			sum=c[i];
			j=0;
			continue;
		}
		j++;
		b[i]-=a[i]-a[j];
	}
	cout<<sum;
	return 0;
 } 
