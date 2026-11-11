#include<bits/stdc++.h>
using namespace std;

int n;
struct number {
	long long num;
	char c;
}c[200005],a[100005],b[100005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> c[i].num >> c[i].c;
	for (int i = 1;i <= (n + 1) / 2; i++)	{
		a[i].num = c[i].num;
		a[i].c = c[i].c;
	}
	for (int i = 1; i <= n / 2; i++) {
		b[i].num = c[n - i + 1].num;
		b[i].c = c[n - i + 1].c;
	}
	long long sum = 0;
	int topa = 1, topb = 1;
	while((a[(n + 1)/2].num != 0) && (b[n / 2].num != 0)) {
		if(b[topb].num >= a[topa].num) {
			if(a[topa].c != b[topb].c)
				sum += min(b[topb].num, a[topa].num);
			b[topb].num -= a[topa].num;
			a[topa].num = 0;
			topa++; 
		}
		else {
			if(a[topa].c != b[topb].c)
				sum += min(b[topb].num, a[topa].num);
				a[topa].num -= b[topb].num;
			b[topb].num = 0;
			topb++; 
		}
	
	}cout << sum; 
}

