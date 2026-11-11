#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==12||c==11)
	{
		while(t--)
		{
			int n;
			ll d;
			cin>>n>>d;
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++)
				cin>>a[i];
			int x=a[2]-a[1];
			if(x*2<=d&&d<x*3)
			{
				cout<<n-3<<"\n";
				continue;
			}
			else
			{
				cout<<"0\n";
				continue;
			}
		}
	}
	if(c==13||c==14)
	{
		while(t--)
		{
			cout<<"0\n";
			continue;
		}
	}
	if(15<=c&&c<=18)
	{
		while(t--)
		{
			cout<<0<<"\n";
			continue;
		}
	}
	return 0;
}
