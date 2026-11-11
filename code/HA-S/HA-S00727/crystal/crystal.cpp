#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n,m;
	cin >> n >> m;
	int arr[500005] = {};

	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr + 0,arr + n);

	long long maxnum = -1;

	for(int i = n - 1; i >= 0; --i) {

		long long cnt = 0, need = 0;

		for(int j = i ; j >= 0; --j) {

			if(arr[j] > arr[i]) {
				continue;
			} else {
				need += arr[i] - arr[j];

				if(need > m) {
					break;
				}

				cnt++;
			}

		}

		maxnum = max(cnt, maxnum);
	}

	cout << maxnum;

	return 0;
}
