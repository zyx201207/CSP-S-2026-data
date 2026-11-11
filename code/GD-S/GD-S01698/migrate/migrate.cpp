#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,t;
	cin>>c>>t;
		freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int k=0;int i=1;
		while(i<=n)
		{
			int f;
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[i]-a[j])>m)
				{
					f=j-1;k++;
					break;
				}
			}
			i=f;
			i++;
		}
	if(n%m!=1)k++;
	cout<<k/2;
	}
}
