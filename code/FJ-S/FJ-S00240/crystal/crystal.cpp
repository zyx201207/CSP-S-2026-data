#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
ll n,m,a[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	ll p=0,k=0;
	for(int i=2;i<=n;i++)
	{
		p+=(i-1-k)*(a[i]-a[i-1]);
		while(p>m)
		{
			p-=a[i]-a[++k];
		}
		ans=max(ans,i-k);
	}
	cout<<ans;
	return 0;
}
