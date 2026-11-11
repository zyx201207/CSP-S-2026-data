#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,s,v,ans,a[2000005],f[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		ans=0;
		cin >> n >> d;
		for(long long i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		v=a[2]-a[1];
		s=d/v;
		if(s<=1) ans=0;
		else ans=n-(s*2-1);
		if(ans<0) cout << 0;
		else cout << ans;
		cout << endl;
	}
	return 0;
}
