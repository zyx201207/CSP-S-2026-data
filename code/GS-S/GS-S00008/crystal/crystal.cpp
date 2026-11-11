#include<bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010], c[500010], sum = 0, ans = 0;

int main() {
	//Oct31==Dec25?
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		c[i] = a[i + 1] - a[i];
	long long sum = 0, cptma = 0;
	int malong = 0;
	for (int i = 1; i < n; i++) {
		sum += 1LL* i * c[i];
		if (sum <= m) {
			malong++;
			cptma += c[i];
		}if (sum > m) {
			sum -= 1LL * i * c[i];
			break;
		}
	}
	int front = 1, rear = malong;
	while (rear < n) {
		rear++, front++;
		sum -= cptma;
		sum += malong * c[rear];
		cptma += c[rear];
		cptma -= c[front - 1];
		if (sum > m) continue;
		else {
			while (sum <= m && rear < n) {
				malong++, rear++;
				sum += malong * c[rear];
				cptma += c[rear];
				if (sum > m) {
					cptma -= c[rear];
					sum -= malong * c[rear];
					malong--, rear--;
					break;
				}
			}
		}
	}
	printf("%d", malong + 1);
}
