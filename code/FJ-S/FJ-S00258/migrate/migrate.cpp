#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		long long d,x[2000005]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long num=(x[j]-x[i])/d;
				if(num==1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
