#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int ans=0;
bool vis[N];
vector<int> v,a;

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; i++)
	{
		int x;
		scanf("%lld", &x);
		a.push_back(x);
	}
	for(int k=30; k>=0; k--)
	{
		v.clear();
		for(int i=0; i<a.size(); i++)
			if((a[i]>>k)&1) v.push_back(a[i]);
		if(v.size()>=m)
		{
			ans|=1<<k;
			a.clear();
			for(int y:v)
			a.push_back(y);
		}
	}
	printf("%lld", ans);
	return 0;
}
