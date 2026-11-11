#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans;
int a[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]==2*d-1) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
