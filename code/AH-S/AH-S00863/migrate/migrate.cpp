//freopen froepen
//#define int long long signed main()
//Oct31==Dec25?
//O(n^2 log n): 10/25 = 40pts(Earned)
//Trick A: 2/25 = 8pts(Earned?)
//Trick B: 2/25 = 8pts(不确定, Earned?)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL MAXN = 2000005, INF = 0x3F3F3F3F3F3F3F3F;
LL C, T, N, D, X[MAXN];
struct Type{
	LL Num, Cnt;
}DP[MAXN];

Type Merge(Type A, Type B) {
	if(A.Num < B.Num) return A;
	if(A.Num > B.Num) return B;
	return {A.Num, A.Cnt + B.Cnt};
}
class Fenwick{
public:
	Type Tree[MAXN];
	void Init() {
		for(int i = 1; i <= N; i++) {
			Tree[i] = DP[i] = {INF, 0};
		}
	}
	void Edit(LL Id, Type Val) {
		for(int i = Id; i <= N; i += ((i) & (-i))) {
			Tree[i] = Merge(Tree[i], Val);
		}
	}
	Type Query(LL X) {
		Type Ans = {INF, 0};
		for(int i = X; i >= 1; i -= ((i) & (-i))) {
			Ans = Merge(Ans, Tree[i]);
		}
		return Ans;
	}
}T3;
void Input() {
	scanf("%lld%lld", &N, &D);
	for(int i = 1; i <= N; i++) scanf("%lld", &X[i]);
}
LL SolveEach(LL Id) {
	T3.Init();
	DP[Id] = {0, 1};
	T3.Edit(Id, DP[Id]);
	LL Ans = 0;
	for(int i = Id - 1; i >= 1; i--) {
		LL Right = upper_bound(X + 1, X + N + 1, X[i] + D) - X - 1;
		DP[i] = T3.Query(Right);
		//cerr << "DP: " << DP[i].Num << ' ' << DP[i].Cnt << '\n';
		if(DP[i].Cnt > 2) DP[i].Cnt = 0;
		if(DP[i].Cnt == 2) {
			Ans++;
		}
		DP[i].Num++;
		T3.Edit(i, DP[i]);
	}
	return Ans;
}
void Solve() {
	LL Res = 0;
	for(int i = 1; i <= N; i++) {
		Res += SolveEach(i);
	}
	//cerr << '\n';
	printf("%lld\n", Res);
}
void Solve1112() {
	LL Start = 0;
	for(int i = 1; i <= N; i++) {
		if(X[i] - X[1] > D) {
			Start = i;
			break;
		}
	}
	if(Start <= 3) {
		printf("0\n");
		return;
	}
	LL Lim = Start - 1;
	LL Len = 2 * Lim - 2;
	LL Ans = 0;
	for(int i = 1, j = Len; j <= N; i++, j++) Ans++;
	printf("%lld\n", Ans);
}
void Solve1314() {
	LL Start = 0;
	for(int i = 1; i <= N; i++) {
		if(X[i] - X[1] <= D && X[N] - X[i] <= D) Start = i;
	}
	LL Res = 0;
	if(Start + 1 <= N) Res += SolveEach(Start + 1);
	if(Start + 2 <= N) Res += SolveEach(Start + 2);
	printf("%lld\n", Res);
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	for(int i = 1; i <= T; i++) {
		Input();
		if(C <= 10) {
			Solve();
			continue;
		}
		if(C == 11 || C == 12) {
			Solve1112();
			continue;
		}
		if(C == 13 || C == 14) {
			Solve1314();
			continue;
		}
	}
	return 0;
}