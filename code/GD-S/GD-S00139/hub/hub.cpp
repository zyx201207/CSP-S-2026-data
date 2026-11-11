#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define MAXN 500005
ll a[MAXN],g[MAXN];

ll n,m;
int main()
{	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	ll j=1;
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{	
		
		g[i]=g[i-1]+a[i];
		while(j<i&&(a[i]*(i-j)-(g[i-1]-g[j-1]))>m)j++;
		ans=max(ans,i-j+1);
	}
	
	cout<<ans<<endl;


	return 0;
}
