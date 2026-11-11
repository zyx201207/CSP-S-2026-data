#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,i,ans=0,n,j;
    long long d;
    long long x[200001];
    cin>>c>>t;
    for(j=1;j<=t;j++)
    {
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(i=1;i<=n-3;i++)
		{
			if(x[i]+d>=x[i+1] and x[i]+d>=x[i+2] and x[i]+d<x[i+3] and x[i+1]+d>=x[i+3])
			{
				ans++;
			}
			else if(x[i+2]+d<x[i+3])
			{
				break;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
    return 0;
}
