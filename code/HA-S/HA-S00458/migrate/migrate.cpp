#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int x[maxn],vis[maxn];
vector<int>g[maxn];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,mx=-1e18,flag=1;
		cin>>n>>d;
		int dd=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>1&&dd==-1)dd=x[i]-x[i-1];
			if(i>2&&x[i]-x[i-1]!=dd)
				flag=0;
		}
		sort(x+1,x+1+n);
		if(x[n]-x[1]<=d)
		{
			cout<<0<<"\n";
			continue;
		}
		if(flag==1||x[n]-x[1]<=10*d)
		{
			
			int d1=d/dd;
			if(d1%2==1)
				cout<<0<<"\n";
			else 
			{
				int ans=0;
				int l=1;
				while(l<=n&&l+d1+1<=n)
					ans++,l++;
				cout<<ans<<"\n";
			}
			continue;
		}
		cout<<0<<"\n";
	}
	return 0;
}
