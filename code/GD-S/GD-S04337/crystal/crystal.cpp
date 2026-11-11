#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> a, diff;
long long usage, lenth, maxlenth, sumofall;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	a.resize(n+1), diff.resize(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a.begin()+1, a.end());
	diff[n] = 0;
	for (int i = 1; i < n; i++) {
		diff[i] = a[i+1]-a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		cout << diff[i] << '\n';
//	}
	usage = m, lenth = 0;
	maxlenth = 0;
	for (int i = 1; i <= n; i++) {
		if (usage >= diff[i]*(lenth+1)) {
			usage-=(diff[i]*(lenth+1));
			sumofall+=diff[i];
//			cout << "1sumof" << diff[i] << ' ' << sumofall;
			lenth++;
		}
		else {
			if (diff[i] <= m) {
//				cout << "ddddra" << diff[i] << '\n'; 
//				cout << "fistra" << usage << '\n';
				while (usage < diff[i]*(lenth+1)) {
//	cout << "higth" << diff[i] << ' ' << lenth << ' ' << usage << ' '<< sumofall<< '\n';
					usage+=sumofall;
					lenth--;
					sumofall-=diff[i-lenth];
				}
//				cout << "thenra" << usage << '\n';
				usage-= (diff[i]*(lenth+1));
				sumofall+=diff[i];
//				cout << "2sumof";
				lenth++;
//			cout << ")k_" << usage;
			}
			else {
				lenth = 0;
				usage = m;
			}
		}
//			cout << ")i_" << usage;
//		cout << lenth << ' ' << usage << ' ' << sumofall<< '\n';
		maxlenth = max(maxlenth, lenth);
	}
	maxlenth = max(maxlenth, lenth);
	cout << maxlenth+1 << '\n';
	return 0;
}
