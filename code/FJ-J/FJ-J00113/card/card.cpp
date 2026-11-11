#include <cstdio>

typedef long long ll;

ll n, m;
ll a[500005];
ll res[300005];
ll deck[500005];

void check(ll i) {
	ll ptr = 0;
	for (int j = i ; j <= n ; j ++) {
		for (int k = ptr ; k > 0 ; k --) {
			if (deck[k] == a[j]) {
				ptr = k - 1;
				break;
			}
		}
		ptr ++;
		deck[ptr] = a[j];
	}
	for (int j = 1 ; j <= ptr ; j ++) {
		res[deck[j]]++;
	}
}

void work1() {
	for (int i = 1 ; i <= n ; i ++) {
		check(i);
	}
	for (int i = 1 ; i <= m ; i ++) {
		printf("%lld ", res[i]);
	}
}

ll rev[500005];
void work2() {
	for (int i = 1 ; i <= n ; i ++) {
		if (rev[a[i]] == 0) rev[a[i]] = i;
	}
	rev[m+1] = n+1;
	for (int i = 1 ; i <= m ; i ++) {
		res[i] += rev[i+1]-1;
	}
	for (int i = 1 ; i <= m ; i ++) {
		printf("%lld ", res[i]);
	}
}

void checkk(ll i, ll mult) {
	ll ptr = 0;
	for (int j = i ; j <= n ; j ++) {
		for (int k = ptr ; k > 0 ; k --) {
			if (deck[k] == a[j]) {
				ptr = k - 1;
				break;
			}
		}
		ptr ++;
		deck[ptr] = a[j];
	}
	for (int j = 1 ; j <= ptr ; j ++) {
		res[deck[j]]+=mult;
	}
}

ll mult[500005];
void work3() {
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%lld", &a[i]);
		if (a[i] == a[i-1]) {
			i--;
			n--;
		}
		mult[i] ++;
	}
	for (int i = 1 ; i <= n ; i ++) {
		checkk(i, mult[i]);
	}
	for (int i = 1 ; i <= m ; i ++) {
		printf("%lld ", res[i]);
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
//	if (m == 2) {
//		work3();
//		return 0;
//	}
	bool spa = true;
	for (int i = 1 ; i <= n ; i ++) {
		scanf("%lld", &a[i]);
		if (a[i] < a[i-1]) spa = false;
	}
	if (spa) work2();
	else work1();
	return 0;
}
