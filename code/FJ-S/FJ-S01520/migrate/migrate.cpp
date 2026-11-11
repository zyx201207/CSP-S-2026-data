#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		
		if(c==11||c==12)
		{
			long long delta=x[2]-x[1];
			long long jump=d/delta;
			if(jump<2) cout<<0<<'\n';
			else cout<<max(0ll,n+1-2*jump)<<'\n';
		}
		
		else
		{
			long long ans=0;
			long long r=1;
			for(int i=1;i<=n;i++)
			{
				while(x[r]-x[i]<=d) r++;
				if(r>n) break;
				if(r-i==3) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
} 
