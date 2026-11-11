#include<bits/stdc++.h>
using namespace std;
int ma=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(ma<min(a[i],a[j]))
			{
				ma=min(a[i],a[j]);
			}
		}
	}
	cout<<ma;
	return 0;
}

