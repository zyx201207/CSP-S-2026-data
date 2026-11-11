#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
bool s[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=30;k>=0;k--)
	{
		int cnt=0,mk=1<<k;
		for(int i=1;i<=n;i++)
		{
			if(s[i]) continue;
			if(a[i]&mk) cnt++;
		}
		if(cnt<m) continue;
		ans+=mk;
		for(int i=1;i<=n;i++)
		{
			if(s[i]) continue;
			if(!(a[i]&mk)) s[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
