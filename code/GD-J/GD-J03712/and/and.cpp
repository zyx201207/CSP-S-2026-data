#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int sum[35];
bool vis[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		vis[i]=1;
	}
	int ans=0;
	for(int i=32;i>=0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])continue;
			if(a[j]&(1ll<<i))sum[i]++;
		}
		//cout << sum[i] <<" "<<i <<endl;
		if(sum[i]>=m)
		{
			ans+=(1ll<<i);
			//cout << ans <<"|"<<(1ll<<i)<<endl;
			for(int j=1;j<=n;j++)
			{
				if(!(a[j]&(1ll<<i)))vis[j]=0;
			}
		}
	}
	cout << ans<<endl;
	return 0;
} 
