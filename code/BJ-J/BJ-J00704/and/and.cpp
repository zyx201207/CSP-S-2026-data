#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+10;
ll a[N];
bool vis[N],vis1[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll ans=0;
	for(ll i=30;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++) vis1[j]=0;
		for(int j=1;j<=n;j++)
		{
			if(((a[j]>>i)&1)&&!vis[j]) cnt++;
			else vis1[j]=true;
		}
		if(cnt>=m) ans+=(1ll<<i);
		for(int j=1;j<=n&&cnt>=m;j++) vis[j]=(vis1[j]||vis[j]);
	}
	cout<<ans;
	return 0;
}
