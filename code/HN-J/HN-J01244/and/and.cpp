#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxn=0;
bool vis[200005],l[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	int k=log2(maxn);
	int ans=0;
	for(int i=k;i>=0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			l[j]=vis[j];
			if(!(a[j]&(1<<i))) l[j]=true;
		}
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=(!l[j]);
		if(cnt>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++) vis[j]=l[j];
		}
	}
	cout<<ans;
	return 0;
}

