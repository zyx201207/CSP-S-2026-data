#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
int sum = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int pj = sum / n;	
	int p[500005];
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - pj;
		if(p[i] < 0)
			p[i] -= 2 * p[i];
	}
	sort(p + 1, p + n + 1);
	int sum1 = 0;
	int m1 = m;
	for (long long i = 1;i <= n; i++) {
		if(m1 - p[i] >= 0) {
			sum1++;
			m1 -= p[i];
		}
		else 
			break;
	}
	pj = pj + 1;
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - pj;
		if(p[i] < 0)
			p[i] -= 2 * p[i];
	}
	sort(p + 1, p + n + 1);
	int sum2 = 0;
	int m2 = m;
	for (long long i = 1;i <= n; i++) {
		if(m2 - p[i] >= 0 ) {
			sum2++;
			m2 -= p[i];
		}
		else 
			break;
	}
	pj = pj - 1;
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - pj;
		if(p[i] < 0)
			p[i] -= 2 * p[i];
	}
	sort(p + 1, p + n + 1);
	int sum3 = 0;
	int m3 = m;
	for (long long i = 1;i <= n; i++) {
		if(m - p[i] >= 0) {
			sum3++;
			m -= p[i];
		}
		else 
			break;
	}
	pj = pj + 2;
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - pj;
		if(p[i] < 0)
			p[i] -= 2 * p[i];
	}
	sort(p + 1, p + n + 1);
	int sum4 = 0;
	int m4 = m;
	for (long long i = 1;i <= n; i++) {
		if(m4 - p[i] >= 0 ) {
			sum4++;
			m4 -= p[i];
		}
		else 
			break;
	}
	pj = pj - 2;
	for (int i = 1; i <= n; i++) {
		p[i] = a[i] - pj;
		if(p[i] < 0)
			p[i] -= 2 * p[i];
	}
	sort(p + 1, p + n + 1);
	int sum5 = 0;
	int m5 = m;
	for (long long i = 1;i <= n; i++) {
		if(m5 - p[i] >= 0 ) {
			sum5++;
			m5 -= p[i];
		}
		else 
			break;
	}
	cout << max(max(max(max(sum1, sum2), sum3), sum4), sum5);
	return 0;
}/*
10 5
1 1 2 3 3 3 3 3 3 4
*/
