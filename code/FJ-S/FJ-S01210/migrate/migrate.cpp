#include<bits/stdc++.h>
using namespace std;
int c,t,d, ans;
long long n,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(long long i=0;i<=n;i++)
		{
			cin>>x[i];
		}
		for(long long i=1;i<=n;i++)
		{
			if(x[i+3]-x[i]>d&&x[i+4]-x[i]<d)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
