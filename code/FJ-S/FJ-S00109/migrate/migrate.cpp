#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		bool v[2000005];
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			v[x[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			bool ok=true;
			for(int j=x[i];j<=x[i]+d;j++)
			{
				if(v[j]==1)
				{
					sum++;
				}
				if(sum>2) ok=false;
			}
			if(ok==false||sum<2) ans+=0;
			else ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
