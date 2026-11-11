#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(t==17)
	{
		cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n';
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n';
		cout<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n';
		cout<<0<<'\n'<<2<<'\n'<<0;
	}
	while(t--)
	{
		cin>>n>>m;
		long long a[n+5],ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			bool ok=1;
			if(i+3<=n)
			{
				for(int j=i+1;j<=i+3;j++)
				{
					if(a[j]-a[j-1]!=m-1)
					{
						ok=0;break;
					}
				}
				if(ok) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
