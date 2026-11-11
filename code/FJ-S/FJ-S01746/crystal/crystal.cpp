#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1e2;
int n,m,ans,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i-1,p=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)+s[mid-1]-s[i]<=m) r=mid-1,p=mid;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
}