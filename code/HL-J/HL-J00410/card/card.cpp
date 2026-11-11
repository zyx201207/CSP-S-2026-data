#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],d[500005],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum=0;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]])
			{
				while(d[sum]!=a[j])
				{
					b[d[sum]]--;
					sum--;
				}
			}
			else
			{
				b[a[j]]++;
				d[sum+1]=a[j];
				sum++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
			b[j]=0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<c[j]<<' ';
	}
	return 0;
}
