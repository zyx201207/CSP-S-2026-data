#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=0x3f3f3f3f3f3f;
int c,t,a[N],mn,mx,z=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		mn=INF;mx=-INF;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		int x=a[2]-a[1];
		if(d<x||a[2]==a[1])
		{
			cout<<0<<'\n';
			continue;
		}
		if(d>(mx-mn)/2) 
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=(mx-mn)*2/d;
		if(ans<0)
		{
			cout<<0<<'\n';
			continue;
		}
		if((mx-mn)*2%d==0) ans--;
		cout<<ans<<'\n';
	}
	return 0;
}
