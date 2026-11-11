#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[(int)5e5+5];
ll b[(int)5e5+5];
ll c[(int)5e5+5];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[n]=0;
	for(int i=n-1;i>=1;i--)
	{
		b[i]=a[n]-a[i];
		c[i]=b[i];
	}
	for(int i=n;i>=1;i--)
	{
		c[i]+=c[i+1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			ll len=(i-mid+1);
			if(c[mid]-c[i]-1ll*(len-1)*b[i]<=m)r=mid;
			else l=mid+1;
		}
//		cout<<i-l+1<<' '<<l<<'\n';
		ans=max(ans,i-l+1ll);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*
6 3
-10000 -1000 0 1 2 3
*/
