#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],n,m,cnt,ans=1,last=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*(i-last);
		if(cnt<=m)
			ans=max(ans,i-last+1);
		else
		{
			while(cnt>m)
				cnt-=(a[i]-a[last++]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
