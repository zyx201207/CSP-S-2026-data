#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505];
long long minn=10000000000000;
long long sum;
void dfs(int l,int r,long long s,int p)
{
	if(p>m)	return;
	if(minn<s)	return;
	if(l==r)
	{
		minn=min(minn,s);
		return;
	}
	s+=w[l];
	for (int i = 1;i <= k[l];i++)
	{
		dfs(a[l][i],r,s+t[l][i],p+1);
	}
	s-=w[l];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)	cin >> a[i][j] >> t[i][j];
	}
	int x,y;
	for (int i = 1;i <= q;i++)
	{
		cin >> x >> y;
		sum=0;
		dfs(x,y,0,0);
		cout << minn << "\n";
		minn=10000000000000;
	}
	return 0;
}
