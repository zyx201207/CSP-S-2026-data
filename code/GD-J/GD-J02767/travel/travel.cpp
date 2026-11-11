#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int eps = 1e-12;
const int N = 1e5 + 20;
int a, b, x, y;
char c, d;
//表示a车厢x排c座,b车厢y排d座
inline bool pdtc (char p, char q)
{
	//判断是否在右侧 
	if (p == 'D' && q == 'F') return 1;
	if (p == 'F' && q == 'D') return 1;
	//判断不都是在右侧,异侧的返回0 
	if (p == 'F') return 0;
	if (p == 'D') return 0;
	if (q == 'F') return 0;
	if (q == 'D') return 0;
	//剩下都是同侧 
	return 1;
}
inline bool pdxl (int p, int q)
{
	//判断是否在右侧相邻 
	if (p == 'D' && q == 'F') return 1;
	if (p == 'F' && q == 'D') return 1;
	//判断是否在左边相邻
	//判断不都是在右侧,异侧的返回0 
	if (p == 'F') return 0;
	if (p == 'D') return 0;
	if (q == 'F') return 0;
	if (q == 'D') return 0;
	//剩下同侧，只有AC时不相邻
	if (p == 'A' && q == 'C') return 0;
	if (p == 'C' && q == 'A') return 0;
	return 1; 
} 
int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
//	cout.tie (0);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	cin >> a >> x >> c >> b >> y >> d;
	if (a == b) cout << 1;
	else cout << 0;
	if (a == b && x == y) cout << 1;
	else cout << 0; 
	if (a == b && x == y && pdtc (c, d)) cout << 1;
	else cout << 0; 
	if (a == b && x == y && pdxl (c, d)) cout << 1;
	else cout << 0; 
	return 0;
}
