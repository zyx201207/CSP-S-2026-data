#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n;
int a[N];
char c[N];
int len;
string s;
int ans;
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    //cin.tie(nullptr), cout.tie(nullptr);
    //ios::sync_with_stdio(false);
    scanf("%lld", &n);
    for(int i = 1; i<=n; i++)
    {
		scanf("%lld", &a[i]);
		len+=a[i];
		cin >> c[i];
		for(int j = 1; j<=a[i]; j++)
			s+=c[i];
	}
	int l = 0, r = n;
	while(l<r)
	{
		if(s[l]!=s[r])
			ans++;
		l++, r--;
	}
	printf("%lld", ans);
    return 0;
}
