#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500001],s[500001];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,an=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid-1,an=mid;
			else l=mid+1;
		}
		ans=max(ans,i-an+1);
	}
	cout<<ans<<"\n";
	return 0;
}
