#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m,a[N],ans,s,l;
//14:54 24minAC pandl
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ans=1,l=1;
	for(int i=2;i<=n;i++)
	{
		if(i==2)s=a[i]-a[i-1];
		else s+=(i-l)*(a[i]-a[i-1]); 
		while(s>m)s-=(a[i]-a[l]),l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
