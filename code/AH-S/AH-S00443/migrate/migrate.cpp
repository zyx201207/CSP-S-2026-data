#include<bits/stdc++.h>
using namespace std;
#define int long long
using ull=unsigned long long;
const int N=2e6+5;
int x[N],c,t,n,x1,x2;
ull d;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		cin>>x1>>x2;
		int xx=x2-x1;
		int k=d/xx;
		for(int i=3;i<=n;i++)
		{
			cin>>x2;
		}
		if(k==2)
			cout<<(n-(x1+d+xx))/xx+1<<'\n';
		else
			cout<<0<<'\n';
	}
	return 0;
}
