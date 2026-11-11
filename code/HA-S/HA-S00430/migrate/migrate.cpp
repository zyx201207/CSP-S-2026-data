#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int a[2000000+10];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long ji=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int o=n;o>=1;o--)
			{
				for(int j=1;j<=o;j++)
				{
					if((a[o]-a[j])<=d&&(o-j)==2)
					{
						ji++;
					}
				}
			}
		}
		cout<<ji<<endl;
	}
	return 0;
}
