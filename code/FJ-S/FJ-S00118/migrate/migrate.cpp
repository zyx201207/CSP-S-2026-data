#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,le;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++)
			cin>>x[i];
		le=d*2-1;
		for(int i=1; i+3<=n; i++)
		{
			if(x[i+3]-x[i] == le)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
