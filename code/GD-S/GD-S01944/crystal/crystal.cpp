#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rig register int
int n,m,a[500005],ans=1;
main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(rig i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(rig i=2,l=1,now=a[1];i<=n;i++)
	{
		now+=a[i];
		while((i-l+1)*a[i]-now>m) now-=a[l++];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
