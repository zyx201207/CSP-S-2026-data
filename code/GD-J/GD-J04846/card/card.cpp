#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define int long long
map<int, int> last;
vector<int> a;
priority_queue<int> b;
int k[300005];
bool v[30005];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		last[t] = i;
		a.push_back(t);
		if(!v[t]) {
			v[t] = 1;
			b.push(t);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n;j++) {
			if(j == i || last[a[j - 1]] <= j) {
				//cout << a[j] << ' ';
				k[a[j]]++;
			}else
				j = last[a[j - 1]];
		}
		//cout << endl;
	}
	while(!b.empty()) {
		cout << k[b.top()] << ' ';
		b.pop();
	}
}
