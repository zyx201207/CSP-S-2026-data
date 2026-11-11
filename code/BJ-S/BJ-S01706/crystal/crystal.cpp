#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i,mid,tmp=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) r=mid-1,tmp=mid;
			else l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
}