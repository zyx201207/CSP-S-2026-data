#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+200;
ll c,t,n,d;
ll a[maxn];
void sol()
{
	cin>>n>>d;
	ll cnt=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=4;i<=n;++i)
	{
		if(a[i-1]+d>=a[i] and a[i-2]+d>=a[i] and a[i-3]+d<a[i]) cnt+=(i-3);
	}
	cout<<cnt<<'\n';
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		sol();
	}
} 
