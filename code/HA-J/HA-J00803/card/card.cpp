#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],b[3005],c[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;)
		{
			if(c[a[j]]==j)
			{
				b[a[j]]++;
				j++;
			}
			else
			{
				j=c[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
