#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int x[N];
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
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(n>=25000)
		{
			if(x[2]-x[1]>d)
			{
				cout<<0<<endl;
				continue; 
			}
				
		}
		if(n<4)
		{
			cout<<0<<endl;
		}
		for(int i=1;i+3<=n;i++)
		{
			if(abs(x[i+3]-x[i+1])<=d&&abs(x[i+2]-x[i])<=d&&abs(x[i+3]-x[i])>d)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
	


