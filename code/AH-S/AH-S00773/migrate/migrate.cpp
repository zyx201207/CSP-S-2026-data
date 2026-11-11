#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[1000000],ans;
struct node
{
	long long x,s;
}f[1000000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				f[j].x=1e17,f[j].s=0;
			f[i].x=0,f[i].s=1;
			for(int j=i;j<=n;j++)
			{
				if(f[j].s==2)
					ans++;
				for(int k=j+1;k<=n && a[j]>=a[k]-m;k++)
				{
					if(f[k].x>f[j].x+1)
						f[k].x=f[j].x+1,f[k].s=1;
					else if(f[k].x==f[j].x+1)
						f[k].s++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}


