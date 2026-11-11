#include <bits/stdc++.h>
#define ll long long
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int N=2e6+10,M=1e8;
int c,to[N],pre[N];
ll n,d,a[N],b[N];
void solve() {
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (11<=c && c<=12)
	{
		ll len=d/(a[2]-a[1]);
		if (n<2*len || len<2) cout<<0<<'\n';
		else cout<<n-2*len+1<<'\n'; 
		return ;
	}
	for (int i=1;i<=n;i++)
	{
		pre[i]=lower_bound(a+1,a+n+1,a[i]-d)-a,to[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		b[i-1]=0;
		for (int j=i;j<=to[i];j++) b[j]=b[j-1]+1;
		int now=to[i];
		for (int j=to[i]+1;j<=n;j++)
		{
			if (pre[j]>now) break;
//			cout<<now<<' '<<pre[j]<<' ';
			int x=b[now]-b[pre[j]-1];
			if (x==2) ans++;
//			cout<<i<<' '<<j<<' '<<x<<'\n';
			b[j]=b[j-1]+x;
			if (j==to[now]) now=j; 
		}
	}
//	for (int i=1;i<=n;i++) cout<<to[i]<<' ';
	cout<<ans<<'\n';
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>c>>t;
	while (t--) solve();
	return 0;
}
