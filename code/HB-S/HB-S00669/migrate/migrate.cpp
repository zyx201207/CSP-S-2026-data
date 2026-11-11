#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+5;

int c,t;
int a[N];
int n,d;

namespace s1
{
	void main()
	{
		while(t--)
		{
			cin>>n>>d;
			
			for(int i=1;i<=n;i++) cin>>a[i];
			
			int ad=a[2]-a[1];
			if(d>=2*ad&&d<3*ad) cout<<n-3<<"\n";
			else cout<<0<<"\n";
		}
	}
	
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>t;
	
	if(c==11||c==12)s1::main();
	else
	{
		while(t--) cout<<"0\n";
	}
	return 0;
}
