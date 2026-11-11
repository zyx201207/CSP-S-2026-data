#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int j=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=(i-j)*(a[i]-a[i-1]);
		while(j<=i&&cnt>m)
		{
			cnt-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}

