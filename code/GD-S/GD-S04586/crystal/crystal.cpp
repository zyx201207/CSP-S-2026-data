#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
int ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
		for(int l=1,r=i-1;l<=r;)
		{
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(s[i-1]-s[mid-1])<=m)
				ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
