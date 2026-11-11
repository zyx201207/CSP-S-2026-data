#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],b[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=n;i>=2;i--) b[i]+=b[i+1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]+b[i];
	int ans=1;
	for(int i=n;i>=2;i--)
	{
		int l=2,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			long long x=s[i]-s[mid-1]-(i-mid+1)*b[i+1];
			if(x<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
