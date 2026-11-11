#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	int ll=1,need=0;
	for(int i=1;i<=n;i++)
	{
		int rr=i+1;
		int cnt=1,m1=m;
		need+=(i-ll)*(a[i]-a[i-1]);
		while(ll<=i&&need>m)
		{
			need-=(a[i]-a[ll]);
			ll++;
		}
		cnt=max(cnt,i-ll+1);
		while(rr<=n&&a[rr]==a[i])
		{
			cnt++;
			rr++;
		}
		i=rr-1;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
