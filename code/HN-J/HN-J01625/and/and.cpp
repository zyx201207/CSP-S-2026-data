#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=(1<<30);k;k>>=1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		cnt+=!b[i]&&(a[i]&k);
		if(cnt>=m)
		{
			ans+=k;
			for(int i=1;i<=n;i++)
			if(!(a[i]&k))b[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
