#include <bits/stdc++.h>
using namespace std;
struct Qj {
	long long l, r;
	Qj(long long _l, long long _r) : l(_l), r(_r) {
	}
};
vector<pair<Qj, char>> vec;
vector<pair<Qj, char>> mvec;
int n;
long long sum = 0;

void func(pair<Qj, char> P) {
	Qj pQ = P.first; char pC = P.second;
	for (int i = n - 1; i >= n / 2 - 1; i--) {
		Qj qQ = vec[i].first; char qC = vec[i].second;
		if (qC == pC) continue;
		if (qQ.l <= pQ.l && pQ.r <= qQ.r) {
			sum += (pQ.r - pQ.l + 1);
		} else if (qQ.l <= pQ.l && qQ.r >= pQ.l) {
//			cout << "1修改区间["<<pQ.l<<", "<<pQ.r<<"]与["<<qQ.l<<", "<<qQ.r<<"]重合 + "<<(qQ.r - pQ.l + 1)<<"\n";
			sum += (qQ.r - pQ.l + 1);
		} else if (pQ.l <= qQ.l && qQ.r <= pQ.r) {
//			cout << "2修改区间["<<pQ.l<<", "<<pQ.r<<"]与["<<qQ.l<<", "<<qQ.r<<"]重合 + "<<(qQ.r - qQ.l + 1)<<"\n";
			sum += (qQ.r - qQ.l + 1);
		} else if (qQ.l <= pQ.r && qQ.r >= pQ.r) {
//			cout << "3修改区间["<<pQ.l<<", "<<pQ.r<<"]与["<<qQ.l<<", "<<qQ.r<<"]重合 + "<<(pQ.r - qQ.l + 1)<<"\n";
			sum += (pQ.r - qQ.l + 1);
		}
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		int len; char ch;
		cin >> len >> ch;
		vec.push_back(make_pair(Qj(cnt, cnt + len - 1), ch));
		cnt += len;
	}
	for (int i = 0; i <= n / 2; i++) {
		Qj q = vec[i].first;
		Qj nq = Qj(cnt - q.r - 1, cnt - q.l - 1);
		if (nq.l <= q.l) continue;
		mvec.push_back(make_pair(nq, vec[i].second));
	}
	
	for (int i = 0; i < mvec.size(); i++) {
		func(mvec[i]);
	}
	
	cout << sum << endl;
	return 0;	
}
