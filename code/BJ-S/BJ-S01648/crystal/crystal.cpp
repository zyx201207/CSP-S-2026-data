// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 5e5+50;
ll a[N], m;
int n;

inline bool check(int k){
	ll sum = 0;
	for (int i = 1;i<=k;i++) sum += a[i];
	for (int i = 1;i+k-1<=n;i++){
		if (a[i+k-1]*k-sum<=m) return 1;
		sum += a[i+k], sum -= a[i];
	}
	return 0;
}

int main(){
	// freopen("input.txt", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n, m);
	for (int i = 1;i<=n;i++) read(a[i]);
	sort(a+1, a+n+1);
	int l = 1, r = n, mid;
	while (l<=r){
		mid = l+r>>1;
		if (check(mid)) l = mid+1;
		else r = mid-1;
	}
	printf("%d\n", r);
	return 0;
}