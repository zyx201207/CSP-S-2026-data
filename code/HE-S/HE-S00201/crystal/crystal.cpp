#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int l=1,ans=0;
	ll now=0;
	for(int i=1;i<=n;i++)
	{
		now=a[i]*(i-1-l+1)-(b[i-1]-b[l-1]);
		while(l<i&&now>m)
		{
			now-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
