#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010;
int n,ans;
ll m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int lb=0,ub=i;
		while(lb+1<ub)
		{
			int mid=lb+ub>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) ub=mid;
			else lb=mid;
		}
		ans=max(ans,i-ub+1);
	}
	cout<<ans;
	return 0;
}
