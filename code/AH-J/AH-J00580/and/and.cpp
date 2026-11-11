#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],m,ans;
bool vis[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i],vis[i]=true;
	for(ll i=30;i>=0;i--)
	{
		ll cnt=0,b=1ll<<i;
		for(ll j=1;j<=n;j++) if(vis[j]&&(a[j]&b)) cnt++;
		if(cnt<m) continue;
		ans+=b;
		for(ll j=1;j<=n;j++) if(vis[j]&&!(a[j]&b)) vis[j]=false;
	}
	cout<<ans;
}
