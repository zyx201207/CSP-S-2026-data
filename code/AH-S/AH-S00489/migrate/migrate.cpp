#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long ans=0;
		for(int i=1,j=4;j<=n;i++,j++)
		{
			long long x=max(abs(a[i]-a[j-1]),abs(a[i+1]-a[j]));
			long long y=abs(a[j]-a[i]);
			if(d>=x&&d<y)
				ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
