#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	ll ans=0;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			ll sub=min(a[l],a[r]);
			a[l]-=sub;
			a[r]-=sub;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else
		{
			ll sub=min(a[l],a[r]);
			a[l]-=sub;
			a[r]-=sub;
			ans+=sub;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
