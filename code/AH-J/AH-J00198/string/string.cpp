#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll len;

const int N = 2e5 + 10;
struct Node {
	ll a;
	char c;
};
Node arr[N];
struct Node2 {
	ll l, r;
	char c;
};
Node2 arr1[N];
Node2 arr2[N];

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &(arr[i].a), &(arr[i].c));
		len += arr[i].a;
	}
	ll p = 1;
	for (int i = 1; i <= n; i++) {
		arr1[i].l = p;
		arr1[i].r = p + arr[i].a - 1;
		p += arr[i].a;
		arr1[i].c = arr[i].c;
	}
	p = 1;
	for (int i = 1, j = n; i <= n; i++, j--) {
		arr2[i].l = p;
		arr2[i].r = p + arr[j].a - 1;
		p += arr[j].a;
		arr2[i].c = arr[j].c;
	}
}

void ceShiInit() {
	printf("\n\n");
	for (int i = 1; i <= n; i++) {
		printf("%lld~%lld %c\n", arr1[i].l, arr1[i].r, arr1[i].c);
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld~%lld %c\n", arr2[i].l, arr2[i].r, arr2[i].c);
	}
	printf("%lld\n\n\n", len);
}

int bs(ll x) {
	ll l = 1, r = n, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr2[mid].l <= x && arr2[mid].r >= x) {
			return mid;
		} else if (arr2[mid].l <= x){
			l++;
		} else {
			r--;
		}
	}
	return -1;
}

ll jiShu() {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		int p1 = bs(arr1[i].l);
		int p2 = bs(arr1[i].r);
		//printf("%d %d\n", p1, p2);
		if (p1 == p2) {
			if (arr2[p1].c != arr1[i].c) {
				cnt += arr1[i].r - arr1[i].l + 1;
			}
			continue;
		}
		for (int j = p1; j <= p2; j++) {
			if (arr2[j].c != arr1[i].c) {
				if (j == p1) {
					cnt += arr2[j].r - arr1[i].l + 1;
				} else if (j == p2) {
					cnt += arr1[i].r - arr2[j].l + 1;
				} else {
					cnt += arr2[j].r - arr2[j].l + 1;
				}
			}
		}
	}
	return cnt;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	init();
	//ceShiInit();
	ll cnt = jiShu();
	cnt /= 2;
	printf("%lld", cnt);
	
	return 0;
}
