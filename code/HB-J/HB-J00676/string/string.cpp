#include <iostream>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 1e8 + 5;

int n;
char ch[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	int sum = 0;
	while (n--) {
		int num;
		char c;
		cin >> num >> c;
		F(i, sum + 1, sum + num) ch[i] = c;
		sum += num;
	}
	
	int ans = 0;
	F(i, 1, sum / 2)
		if (ch[i] != ch[sum - i + 1])
			ans++;
			
	cout << ans;
	return 0;
}
