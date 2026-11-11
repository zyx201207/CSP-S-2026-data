#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[200005],maxx=-1,maxn=1;
void dfs(ll sum,ll num,ll c)
{
	if (c==m)
    {
		maxx=max(maxx,sum);
		return;
    }
    if (num>=n+1) return;
    if (n-num+1 < m-c) return;
    dfs((sum&a[num]),num+1,c+1);
    dfs(sum,num+1,c);
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	for (ll i=1;i<=31;i++) maxn*=2;
	maxn--;
    cin>>n>>m;
    for (ll i=1;i<=n;i++) cin>>a[i];
    dfs(maxn,1LL,0LL);
    cout<<maxx;
    return 0;
}
