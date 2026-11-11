#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crad.in","r",stdin);
	freopen("crad.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n];
	int x[m];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			x[i]=a[j];
			if(x[i]==x[i])
			{
				cout<<x[i];
			}
		}
	}
	return 0;
}
