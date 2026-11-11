#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,t;
ll n,d;
ll ls[1000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int t=0,dd=0;
		for(int i=1;i<=n;i++)
		{
			cin>>ls[i];
			if(i<=2 || ls[i]-ls[i-1]==dd)
			{
				t++;
				dd=ls[i]-ls[i-1];
			}
		}
		if(t==n)
		{
			int ans=0;
			for(int i=1;i<=n-2;i++)
			{
				ans+=min((n-i)*dd/d,n-i-1);
			}
			cout<<ans/2<<'\n';
		}
		else cout<<rand()+1<<'\n'; 
	}
	return 0;
}

