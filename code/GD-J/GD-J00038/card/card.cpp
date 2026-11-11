#include <iostream>
#include <stack>

using namespace std;

const int N = 5e5 + 10;
int n, m, a[N], ans[N];

void calc(int st) {
	stack <int> s;
	for (int i = st; i <= n; i ++) {
		bool flag = false;
		stack <int> t;
		t = s; 
		while (!s.empty()) {
			if (s.top() == a[i]) {
				flag = true;
				s.pop();
				break;
			}
			s.pop();
		}
		if (!flag) s = t;
		s.push(a[i]);
	}
	while (!s.empty()) {
		ans[s.top()] ++;
		s.pop();
	}
}

void BaoLi() {
	for (int i = 1; i <= n; i ++)
		calc(i);
	for (int i = 1; i <= m; i ++)
		cout << ans[i] << ' ';
	puts("");
}

void planA() {
	for (int i = 1; i <= n; i ++) {
		if (a[i] == a[n])
			ans[a[i]] ++;
		else
			ans[1] ++, ans[2] ++;
	}
	cout << ans[1] << ' ' << ans[2] << '\n';
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
		
	if (n <= 500) BaoLi();
	else if (m <= 2) planA();
	
	return 0;
}
