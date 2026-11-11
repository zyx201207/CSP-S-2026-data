#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		bool ok=1;
		int b=x[2]-x[1];
		for(int i=3;i<=n;i++)
		{
			if(x[i]-x[i-1]!=b)
			{
				ok=0;
				break;
			}
		}
		if(ok)
		{
			if(d<b*2||x[n]-x[1]==d)
			{
				cout<<0;
				return 0;
			}
			cout<<n-3<<endl;
			return 0;
		}
		for(int l=1;l<n;l++)
		{
			for(int r=l+3;r<=n;r++)
			{
				if(x[r]-x[l]>=2*d)break;
				else
				{
					int p=x[r]-d,q=x[l]+d;
					int num=0;
					for(int i=1;i<=n;i++)
					{
						if((x[i]>=p&&x[i]<=q)||(x[i]<=p&&x[i]>=q))num++;
					}
					if(num==2){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
