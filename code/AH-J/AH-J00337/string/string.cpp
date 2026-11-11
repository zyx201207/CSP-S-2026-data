# include <bits/stdc++.h>
# define int long long
using namespace std;

const int N = 2e5+5;
int n,k[N],q[N],ans;
char s[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld",&k[++k[0]]);
		cin>>s[k[0]];
		if (s[k[0]] == s[k[0]-1]) k[0]--,k[k[0]] += k[k[0]+1];
	}
	for (int i = 1; i <= k[0]; i++) q[i] = k[i],printf("%lld ",k[i]);
	for (int i = 1,j = k[0]; i <= k[0]; i++,j--)
	{
		int t = min(k[i],q[j]);
		k[i] -= t;
		q[j] -= t;
		if (s[i] != s[j]) ans += t;
		if (k[i] != 0) i--;
		if (q[j] != 0) j++;
	}
	printf("%lld",ans/2);
	return 0;
}
