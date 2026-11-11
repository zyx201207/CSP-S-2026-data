#include <iostream>
#include <queue>
#include <algorithm>
#define int long long
#undef _
using namespace std;
typedef long long ll;

// string.cpp

// WHY IS IT SO HARD?!!!!
// IT JUST T2!!!!
// 100PTS PLZ!!!
// YEAH!!!

const int N = 1e6 + 3;

int n;
int tot = 0, ToT = 0;
int A[N], S[N];
char C[N];
int B[N];

struct node {
	int l, r;
	char cl, cr;
} D[N];

// inline int abs(int _) { return _ < 0 ? -_ : _; }

void work(int L, int R, char ch, bool f) {
	int l1 = 1, r1 = ToT;
	while (l1 < r1) {
		int mid = (l1 + r1) >> 1;
		if (D[mid].l == L) {
			l1 = r1 = mid;
			break;
		} else if (D[mid].l < L) {
			l1 = mid + 1;
		} else {
			r1 = mid - 1;
		}
	}
	
	int l2 = 1, r2 = ToT;
	while (l2 < r2) {
		int mid = (l2 + r2) >> 1;
		if (D[mid].r == R) {
			l2 = r2 = mid;
			break;
		} else if (D[mid].r < R) {
			l2 = mid + 1;
		} else {
			r2 = mid - 1;
		}
	}
	
	for (int i = r1; i <= l2; ++i) {
		if (!f) D[i].cl = ch;
		else D[i].cr = ch;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	// Welcome to Read <How To Make AC-en T2>
	
	ll L = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> A[i] >> C[i];
		L += A[i];
	}
	
	if (L & 1) {	// First, wash L to even number
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			sum += A[i];
			if (sum > (L >> 1)) {
				--A[i];
				--L;
				break;
			}
		}
	}
	
	int m = -1;
	for (int i = 1; i <= n; ++i) {	// Second, find the middle one and paint the cut line
		S[i] = S[i - 1] + A[i];
		B[++tot] = abs(S[i] - (L >> 1));
		if (m == -1 && S[i] >= (L >> 1)) m = i;
	}
	
	sort(B + 1, B + tot + 1);	// Add some salt (sort)
	
	// Next, cut it into smaller pieces
	for (int i = 1; i <= tot; ++i) {
		if (B[i] > B[i - 1]) {
			D[++ToT].l = B[i - 1] + 1;
			D[ToT].r = B[i];
		}
	}
	
	// FRIED!!!!!!
	
	for (int i = 1; i <= m; ++i) 
		work((L >> 1) - S[i] + 1, (L >> 1) - S[i - 1], C[i], false);
	
	if (S[m] > (L >> 1)) work(1, S[m] - (L >> 1), C[m], true);
	
	for (int i = m + 1; i <= n; ++i) 
		work(S[i - 1] - (L >> 1) + 1, S[i] - (L >> 1), C[i], true);
		
	// Last, put it out
	ll ans = 0;
	for (int i = 1; i <= ToT; ++i) {
		if (D[i].cl != D[i].cr) ans += (D[i].r - D[i].l + 1);
	}
	cout << ans << endl;
	
	return 0;
} 
