#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const int maxn = 2e5+5;

// 题意: 在长度为 n 的数组 a 中选 m 个数, 问这 m 个数按位与的最大值 

int n,m;
ll ans, res; 
pli a[maxn];

void dfs(int u, int ch, ll res)
{
	if(ch == m && u <= n+1)
	{
		ans = max(ans, res);
		return;
	}
	if(u == n+1) return;
	ll k = a[u].first;
	dfs(u+1,ch+1,(res == -1 ? k : res&k));
	dfs(u+1,ch,res);
}

void b2(int i)
{
	ll x = a[i].first;
	while(x)
	{
		if(x%2 == 1) a[i].second++;
		x /= 2;
	}
}

bool cmp(const pli &x, const pli &y)
{
	return (x.second >= y.second);
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].first;
		a[i].second++;
	}
	
	if(n <= 20)
	{
		dfs(1,0,-1LL); // -1 表示没选
		cout<<ans;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++) b2(i);
		sort(a+1,a+1+n,cmp);
		ans = a[1].first;
		for(int i=2;i<=m;i++) ans &= a[i].first;
		res = ans;
		for(int l=2;l+m-1<=n;l++)
		{
			res |= a[l-1].first; // 把之前的踢掉
			res &= a[l+m-1].first; 
			ans = max(ans,res);
		}
		cout<<ans; 
	}
	
	return 0;
} 
