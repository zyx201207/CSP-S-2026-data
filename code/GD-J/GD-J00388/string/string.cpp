#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans=0;
struct qwe {
	int a;
	char c;
};
deque<qwe> q;
signed main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  cin >> n;
  for(int i = 1; i<= n; ++i) {
    int ai;
    char ci;
    cin >> ai >> ci;
	q.push_back({ai, ci});
  }

  while (!q.empty()) {
  	if (q.size() == 1) break;
  	int minn = min(q.front().a, q.back().a);
  	if (q.front().c != q.back().c) {
  	  	ans += minn;
    }
	if (minn == q.back().a) {
  	  	q.pop_back();
  	  	qwe a = q.front();
  	  	q.pop_front();
  	  	q.push_front({a.a - minn, a.c});
	} else {
		q.pop_front();
		qwe a = q.back();
  	 	q.pop_back();
  	  	q.push_back({a.a - minn, a.c});
	}
  }
  cout<<ans<<"\n";
}
