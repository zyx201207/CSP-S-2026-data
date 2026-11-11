#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(long long i=2;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
			b[a[j]]++;
		}
	}
	for(long long i=0;i<m;i++)
	{
		cout<<b[i+1]<<' ';
	}
	return 0;
}
