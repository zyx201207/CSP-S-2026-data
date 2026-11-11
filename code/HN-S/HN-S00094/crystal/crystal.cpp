#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int a[MAXN],n,m;
signed main(  )
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[l++];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
