#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],b[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n;i++)
		{
			b[i]=a[i]-a[i-1];
		}
		int h=1;
		for(int i=3;i<=n;i++)
		{
			if(b[i]!=b[i-1]) h=0;
		}
		if(h==1) cout<<"0\n";
		else if(d>=(a[n]-a[1])) cout<<n<<"\n";
		else cout<<"1\n";
	}
	return 0;
}
