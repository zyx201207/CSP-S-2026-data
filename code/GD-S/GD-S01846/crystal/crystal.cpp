#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0,nd=0;
	for(int i=1;i<=n;i++)
	{
		nd=nd+(a[i]-a[i-1])*(ll)(i-1);
		if(nd<=m){
			ans=i;
		}
	}
	cout<<ans;
	return 0;
}
