#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;

ll n,m;
ll a[N];
ll ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
		
	for(int i=1;i<=n;i++)
	{
		ll tmp=0;
		ll t=m;
		
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]<=t)
			{
				t-=(a[i]-a[j]);
				tmp++;
			}
			else break;	
		}
		
		ans=max(ans,tmp);
	}
	
	cout<<ans;
	return 0;
}
