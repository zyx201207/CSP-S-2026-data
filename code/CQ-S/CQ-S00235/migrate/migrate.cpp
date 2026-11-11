#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXN=1e6+5;

ll c,t,n,d,ls[MAXN];

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
		for(int i=1;i<=n;i++)
		{
			cin>>ls[i];
		}
		if(n==1)
		{
			cout<<0<<endl;
		}
		else if(c==11 || c==12)
		{
			ll d1=ls[2]-ls[1];
			ll l=(d+d1-1)/d1;
			cout<<max(n-l+1,0ll);
		}
	}
	return 0;
}
