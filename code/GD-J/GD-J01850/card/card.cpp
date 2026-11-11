#include <bits/stdc++.h>
using namespace std;
int where;

bool check(vector<int>& play, int ai, int size) {
	for (int i=0;i<size;i++) {
		if (play[i] == ai) {
			where = i;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	vector<int> a(n);
	cin >> n >> m;
	for (long long i=0;i<n;i++) {
		cin >> a[i];
	}
	vector<int> flag(m);
	for (int k=0;k<n;k++) {
		vector<int> play(500000);
		int size = 1;
		for (int i=k;i<n;i++) {
			if (check(play, a[i], size)) {
				for (int j=where;j<size;j++) {
					play[j] = 0;
				}
				size = where + 1;
				play[size-1] = a[i];
				size++;
			} else {
				play[size-1] = a[i];
				size++;
			}
		}
		for (int i=0;i<size;i++) {
			flag[play[i]-1]++;
		}	
	}
	for (int i=0;i<m;i++) {
		cout << flag[i] << ' ';
	}
	cout << endl;
	return 0;
}
