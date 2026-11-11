#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int r=0;r<t;r++)
	{
		cin>>n>>d;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n-3;i++)
		{
			if(a[i+3]-a[i]<=d)
			{
				continue;
			}
			else
			{
				if(a[i+2]-a[i]<d&&a[i+3]-a[i+1]<d)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
