#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define TIII tuple<int,int,int>
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define il inline
#define rg register
#define fi first
#define se second
#define MAXN 500005
using namespace std;
int n,m,a[MAXN],b[MAXN],c[MAXN],ans[MAXN];
il void gg(int s)
{
	int cur = 0;
	memset(c,0,sizeof c);
	for (rg int i = s;i<=n;i++)
	{
		if (!c[a[i]])
		{
			b[++ cur] = a[i];
			c[a[i]] = cur;
		}
		else
		{
			for (rg int j = c[a[i]] + 1;j<=cur;j++) c[b[j]] = 0,b[j] = 0;
			cur = c[a[i]];
		}
	}
	for (rg int i = 1;i<=cur;i++) ans[b[i]] ++;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (rg int i = 1;i<=n;i++) cin>>a[i];
	for (rg int i = 1;i<=n;i++) gg(i);
	for (rg int i = 1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
