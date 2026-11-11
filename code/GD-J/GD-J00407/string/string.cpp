#include<iostream>
#include<map>
#define int long long

using namespace std;

int a[200010];
char ch[200010];
string s;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		cin >> ch[i];
		for(int j = 1; j <= a[i]; j ++ ) s += ch[i];
	}
	int ans = 0;
	for(int i = 0; i < s.size() / 2; i ++ )
	{
		if(s[i] != s[s.size() - i - 1])
		{
			ans ++ ;
		}
	}
	cout << ans;
	return 0;
}
