#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200000020],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n>>d;
		ans=0;
		for (int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for (int k=1;k<n-1;k++)
		{
			for (int l=k+3;l<=n;l++)
			{
				if ((l-k)%2)
				{
					if ((a[l]-a[k])<=2*d && (l-k)>d)
					{
						ans++;
					}
				}
				
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
