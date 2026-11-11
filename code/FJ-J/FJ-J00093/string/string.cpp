#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int N = 200010, M = 100000010;

int n;
struct Node
{
	int len;
	char val;
} node[N];
char str[M];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	int idx = 0;
	for (int i = 1; i <= n; ++ i )
	{
		cin >> node[i].len >> node[i].val;
		for (int j = 1; j <= node[i].len; ++ j )
			str[idx ++ ] = node[i].val;
	}
	
	int res = 0;
	for (int i = 0, j = idx - 1; i < j; ++ i , -- j )
		if (str[i] != str[j]) res ++ ;
	
	cout << res;
	
	return 0;
}
