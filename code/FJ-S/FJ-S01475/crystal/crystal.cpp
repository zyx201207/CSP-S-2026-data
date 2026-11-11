#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
ll a[MAXN],s[MAXN];
int n,m,ans=1;
int dfs(int u)
{
	int t=2;
	ll tot=s[u],sum=s[u];
	if(tot>m) return 1;
	for(int i=u-1;i>1;--i){
		tot+=s[i]+sum;
		sum+=s[i];
		if(tot<=m){
			++t;
			continue;
		}
		return t;
	}
	return t;
}
int main()
{
	std::cin.tie(0)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i) s[i]=a[i]-a[i-1];
	for(int i=n;i>=2;--i){
		ans=max(ans,dfs(i));
		if(ans>=i-1) break;
	}
	cout<<ans;
	return 0;
}
