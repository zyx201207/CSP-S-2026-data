#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
int n, m;
int a[N];
string s;
int ans[M];
int find(char c)
{
	int len = s.size();
	for(int i = 0; i<len; i++)
	{
		if(s[i]==c)
			return i;
	}
	return -1;
}
signed main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    //cin.tie(nullptr), cout.tie(nullptr);
    //ios::sync_with_stdio(false);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i<=n; i++)
		scanf("%lld", &a[i]);
	for(int i = 1; i<=n; i++)
	{
		s = "";
		for(int j = i; j<=n; j++)
		{
			int f = find(a[j]-'0');
			if(f==-1)
				s+=a[j]-'0';
			else
				s.erase(f+1, s.size()-f);
		}
		for(int j = 0; j<s.size(); j++)
			ans[(int)s[j]+'0']++;
	}
	for(int i = 1; i<=m; i++)
		cout << ans[i] << " ";
    return 0;
}
