#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
	int start, end;
	char type;
};
vector<node> a;
vector<int> b;
vector<int> cc;
signed main() {
	freopen("string6.in", "r", stdin);
	// freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	char last = '-';
	int l = 0, st = 0;
	bool la = 0;
	for(int i = 1; i <= n; i++) {
		char c2;
		int c;
		cin >> c >> c2;
		if(c2 == last){
			l += c;
			la = 0;
		}
		else {
			if(last != '-'){
				a.push_back({st, l, last});
				b.push_back(st);
				cc.push_back(l);
			}
			st = l + 1;
			l += c;
			la = 1;
			last = c2;
		}
	}
	a.push_back({st, l, last});
	b.push_back(st);
	cc.push_back(l);
	int cost1 = 0, cost2 = 0;
	int index = 0;
	for(auto i : a) {
		int left = (l - i.end + 1), right = (l - i.start + 1);
		auto from = lower_bound(b.begin(), b.end(), right);
		int ed = distance(b.begin(), from);
		auto e = lower_bound(cc.begin(), cc.end(), left);
		int fr = distance(cc.begin(), e);
		for(int j = fr; j <= ed; j++) {
			if(j == index || j >= a.size())
				continue;
			int st1 = a[j].start, ed1 = a[j].end;
			if(a[j].type != i.type) {
				if(a[j].start < left && a[j].end < left)
					continue;
				if(a[j].start > right && a[j].end > right)
					continue;
				if(a[j].start <= (l - i.end + 1)){
					cost1 += min((l - i.start + 1), a[j].end) - max((l - i.end + 1), a[j].start) + 1;
				}else {
					cost1 += min((l - i.start + 1), a[j].end) - max((l - i.end + 1), a[j].start) + 1;
				}
			}
		}
		index++;
	}
	cout << cost1 / 2;
}

