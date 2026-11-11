#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2e5 + 5;

int n, m, maxa = 0, ans;
int a[N], p[30];
bool cmp(int x, int y) { return x > y; }

bool check(int x)
{
	if (x == -1) return false;
	for (int i = 1; i <= m; i++)
		if (a[i] < p[x])
		{
			for (int j = 1; j < i; j++)
				a[j] -= p[x];
			sort(a + 1, a + n + 1, cmp);
			break;
		}
	return true;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0] = 1;
	for (int i = 1; i <= 29; i++)
		p[i] = p[i-1] * 2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	
	int x = 29;
	while (check(x)) x --;
	ans = a[1];
	for (int i = 1; i <= m; i++)
		ans = ans & a[i];
	cout << ans;
	return 0;
 } 
