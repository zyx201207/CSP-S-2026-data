#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int N=2e6+5;
const long long M=1e18;

int n,d,a[N],vis[N];

void solve()
{
	int ans=0;
	cin>>n>>d;
	long long A;
	for(int i=1;i<=n;++i)
	{
		cin>>A;
		a[i]=A+M; 
	}
	for(int i=4;i<=n;++i)
	{
		if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d)
		{
			if(a[i]-a[i-3]<=d)vis[i]=2;
			else vis[i]=1,++ans;
		}
	}
	for(int i=1,t=0;i<=n;++i)
	{
		if(vis[i]==2)
		{
			t=0;
			continue;
		}
		if(vis[i]==1)continue;
		int j=i+1;
		while(j<=n&&vis[j]==0)++j;
		ans+=t*(j-i);
		t=j-i;
		i=j-1;
	}
	cout<<ans<<'\n';
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
 }
