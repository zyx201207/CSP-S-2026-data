#include <bits/stdc++.h>
#define int long long
using namespace std; 

struct UKE
{
	int num;
	char ch;
}m[200005],m0[200005];

signed main()
{
	// ÓÃscanf,printf!
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans = 0;
	cin >> n; 
	for (int i = 1;i <= n;i++) {
		cin >> m[i].num >> m[i].ch;
		m0[i] = m[i];
	}
	reverse(m0 + 1,m0 + n + 1);
	int i = 1,j = 1;
	while(i <= n / 2 || j <= n / 2)
	{
		int t = abs(m[i].num - m0[j].num);
		m[i].num -= t;
		m0[j].num -= t;
		if (m[i].ch != m0[j].ch)
		{
			ans += t;
		}
		if (m[i].num <= 0) i++;
		if (m0[j].num <= 0) j++;
	}
	printf("%d",ans);
	return 0;
}
