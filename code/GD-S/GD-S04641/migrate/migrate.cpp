#include<bits/stdc++.h>
using namespace std;
int c,t;
const int maxn=2e6+10;
typedef long long ll;
ll x[maxn];
int n; ll d;
int main()
{

	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ll dd;
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    dd=x[2]-x[1];
    ll ans=0;
    for(int i=4;i<=n;i++)
    {
    	if(d%(dd*(i-1))!=0) ans++;
	}
	cout<<ans<<endl;
	}
	return 0;
 } 
