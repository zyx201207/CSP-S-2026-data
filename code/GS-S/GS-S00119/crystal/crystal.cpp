#include<bits/stdc++.h>
const int maxn=5e5;
typedef long long ll;
using namespace std;
ll a[maxn+5],s[maxn+5];;
ll n,m,ans=0;

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	for(int l=1,r=1;r<=n;++r)
	{
		while(1ll*(r-l+1)*a[r]-(s[r]-s[l-1])>m&&l<=r)++l;
		ans=max(ans,0ll+r-l+1);
	}
	cout<<ans<<'\n';
	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int _=1;
//	cin>>_;
	while(_--)solve();
	return 0;
}

