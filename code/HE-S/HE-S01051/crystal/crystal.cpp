#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[500005], sub[500005], sum[500005];
long long ans;

void sift_down(long long arr[], long long start, long long end) {
	long long parent = start;
	long long child = parent * 2;
	while (child <= end) {
		if (child + 1 <= end && arr[child + 1] > arr[child]) child ++;
		if (arr[parent] >= arr[child]) return;
		else {
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2;
		}
	}
}

void heap_sort(long long arr[], long long len) {
	for (long long i = len / 2; i >= 1; i--) sift_down(arr, i, len);
	for (long long i = len; i > 1; i--) {
		swap(a[i], a[1]);
		sift_down(arr, 1, i - 1);
	}
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	heap_sort(a, n);
	for (int i = 1; i <= n; i++) {
		sub[i] = a[n] - a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + sub[i];
	}
//	for (int i = 1; i <= n; i++) {
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++) {
//		cout << sub[i] << ' ';
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++) {
//		cout << sum[i] << ' ';
//	}
//	cout << endl;
	long long l = 1, r = n, len = n;
	while (l <= r) {
//		cout << len << endl;
		bool f = false;
		for (long long i = 1; i + len - 1 <= n; i++) {
			long long j = i + len - 1;
			long long cnt = sum[j] - sum[i - 1] - len * sub[j + 1];
//			cout << i << ' ' << j << ' ' << cnt << endl;
			if (cnt <= m) {
				f = true;
//				cout << "true\n";
				break;
			}
		}
		if (f == true) {
			l = len + 1;
		} else {
			r = len - 1;
		}
		len = (l + r) / 2;
	}
	cout << l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

