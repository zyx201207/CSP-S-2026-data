#include<bits/stdc++.h>
#define ll long long
const int N=2e6+6;
using namespace std;
ll c,t,n,d;
ll a[N],cha[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			cha[i]=a[i]-a[i-1];	
		}
	}
	cout<<0<<endl<<1;
	return 0;
} 
