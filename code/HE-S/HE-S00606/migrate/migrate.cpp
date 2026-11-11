#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d,x[2000005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			int dd=x[2]-x[1];
			int x=d/dd+d/dd-1;
			if(x<=1)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<max(n-x,0ll)<<endl;
			}
		}
	return 0;
} 

