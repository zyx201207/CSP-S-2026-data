//freopen froepen
//#define int long long signed main()
//Oct31==Dec25?
//Predicted score: 100 + 100 + 56 + 40 = 296 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL MAXN = 500005;
LL N, M;
LL Arr[MAXN], Sum[MAXN];
void Input() {
	scanf("%lld%lld", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &Arr[i]);
	}
	sort(Arr + 1, Arr + N + 1);
	for(int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + Arr[i];
	}
}
bool Check(LL R, LL Mid) {
	LL Target = Arr[R] * Mid;
	LL Sum1 = Sum[R] - Sum[R - Mid];
	return Target - Sum1 <= M;
}
void Solve() {
	LL Ans = 0;
	for(int i = 1; i <= N; i++) {
		LL L = 1, R = i + 1;
		while(L + 1 != R) {
			LL Mid = (L + R) / 2;
			if(Check(i, Mid)) L = Mid;
			else R = Mid;
		}
		Ans = max(Ans, L);
	}
	printf("%lld\n", Ans);
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	Input();
	Solve();
	return 0;
}
