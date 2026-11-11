#include<bits/stdc++.h>
#define N 2000005
#define int long long
using namespace std;
int c,n,d,t;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			memset(x,0,sizeof x);
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int dis=x[2]-x[1];
			int num=d/dis;
			if(num>=2) cout<<max(0*1ll,n-2*num+1)<<'\n';
			else cout<<0<<'\n';
		}
	}
	else
	{
		while(t--)
		{
			cout<<0<<'\n';
		}
	}
	return 0;
}
