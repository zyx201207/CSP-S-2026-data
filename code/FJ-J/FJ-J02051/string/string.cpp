#include <bits/stdc++.h>
#define int long long
using namespace std;

struct zh
{
	int a;
	char c;
};

int n,ans,l,r,p;
zh x[200010];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> x[i].a >> x[i].c;
	for(int i = 0,j = n + 1;i < j - 1;)
	{
		if(l == 0) l = x[++i].a;
		if(r == 0) r = x[--j].a;
		p = min(l,r);
		if(x[i].c != x[j].c) ans += p;
		l -= p,r -= p;
	}
	cout << ans;
	return 0;
}

