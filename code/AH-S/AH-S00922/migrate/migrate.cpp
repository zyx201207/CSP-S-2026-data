#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+2;
ll a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T,n,d,P=1;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll cnt=d/abs(a[2]-a[1]);
		if(cnt<2||n-2*cnt+1<0)cout<<0<<'\n';
		else cout<<n-2*cnt+1<<'\n';
	}
	return 0;
}
