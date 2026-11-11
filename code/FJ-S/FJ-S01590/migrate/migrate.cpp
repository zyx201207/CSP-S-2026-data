#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		long long a[n+1];
		for(long long i=1;i<=n;i++)cin>>a[i];
//		cout<<a[2]-a[1]<<" "<<m<<" "<<n<<endl;
		if(c==11||c==12)
		{
			if(m<(a[2]-a[1])*2||m>=(a[2]-a[1])*4)
			{
				puts("0");
				continue;
			}else{
//				long long x=m/(a[2]-a[1]);
				if(m>=(a[2]-a[1])*3)cout<<n-5<<'\n';
				else cout<<n-3<<'\n';
			}
		}else puts("0");
	}
	return 0;
}

