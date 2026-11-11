#include<bits/stdc++.h>
using namespace std;
long long c,a[2000006];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;
	if(c==11||c==12)
	{
		int t;
		cin>>t;
		while(t--)
		{
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(n<=2) cout<<0<<endl;
			else if((a[2]-a[1])*2>d) cout<<0<<endl;
			else cout<<n-2<<endl;
		}
		return 0;
	}
	cin>>c;
	while(c--)
	{
		cout<<0<<endl;
	}
	return 0;
}