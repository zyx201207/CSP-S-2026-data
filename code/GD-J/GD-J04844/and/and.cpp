#include<bits/stdc++.h>
using namespace std;
long long ar[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	sort(ar+1,ar+n+1);
	long long ma=0;
	for(int i=n;i>=1;i--)
	{
		long long c=ar[i];
		for(int j=i;j>i-m;j--)
		{
			c=c&ar[j];
		}
		if(c>ma)
		{
			ma=c;
		}
	} 
	cout<<ma;
	return 0;
}
