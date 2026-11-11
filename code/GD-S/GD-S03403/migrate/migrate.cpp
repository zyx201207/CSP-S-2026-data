#include <bits/stdc++.h>
using namespace std;
const long long N=2e6+3;
long long c,n,d,ma,t,g,a[N],f,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		g=a[2]-a[1];
		ma=d/g;
		f=1;
		while(f<n)
		{
			f+=ma;
			ans+=(n-f);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
