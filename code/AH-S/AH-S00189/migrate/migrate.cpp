#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	long long n,d;
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n<4)cout<<0<<"\n";
		for(int i=4;i<=n;i++)
		{
			int n2=lower_bound(x+1,x+n+1,x[i]-d)-x;
			if(n2==i)continue;
			if(n2+1==i)continue;
			int n1=lower_bound(x+1,x+n+1,x[n2+1]-d)-x;
			int n1up=lower_bound(x+1,x+n+1,x[n2+2]-d)-x;
			ans+=n1up-n1;
		}
		cout<<ans<<"\n";
	}
}
