#include<bits/stdc++.h>
using namespace std;
#define int long long
int max(int a,int b)
{
	return a>b?a:b;
}
int n,m,a[500005],ans,cnt;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++)
	{
		cnt+=(i-j)*(a[i]-a[i-1]);
		while(j<i&&cnt>m) cnt-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
