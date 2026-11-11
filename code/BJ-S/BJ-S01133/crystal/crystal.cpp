#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500086],sum[500086],ans,m;
bool check(int x,int y)
{
	int len=x-y+1;
	//cout<<x<<' '<<y<<' '<<a[x]*len-(sum[x]-sum[y-1])<<'\n';
	if(a[x]*len-(sum[x]-sum[y-1])<=m) return 1;
	return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	cin>>n>>m;
	//cout<<n<<m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,nans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(i,mid)) nans=(i-mid+1),r=mid-1;
			else l=mid+1;
		}
		//cout<<nans<<"***\n";
		ans=max(ans,nans);
	}
	cout<<ans;
    return 0;
}
/*
  5 8
 -3 -1 2 2 7
*/
