#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

int n,m,a[N];
vector<int> now,v;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		now.push_back(a[i]);
	}
	for (int i=30;i>=0;i--)
	{
		v.clear();
		for (int x:now)
		{
			if ((x>>i)&1)
				v.push_back(x);
		}
		if (v.size()>=m) now=v;
	}
	int ans=now[0];
	for (int x:now)
		ans&=x;
	cout << ans << '\n';
	return 0;	
}
