#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int x[2000100];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int p;
		for(int i=1;i<=n;i++) cin>>x[i];
		p=x[2]-x[1];
		if(d<p) cout<<0<<endl;
		int cnt=d%(2*p);
		int w=d/(2*p);
		if(cnt<p) cout<<n-(2*(w+1)-1)<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
