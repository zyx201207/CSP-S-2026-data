#include<bits/stdc++.h> 
using namespace std;
int a[2000005],f[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,x;
	cin>>c>>x;
	while(x--)
	{
		int n,m,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i]=999999999;
		}
		f[1]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
			    if(a[i]-a[j]<=m)
			    {
				    if(f[i]>f[j]+1)
				      f[i]=f[j]+1;
			    }
			}
			int s=0;
			for(int j=1;j<i;j++)
			{
				if(f[i]==f[j]+1)
				  s++;
			}
	        if(s==2)
	          ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
