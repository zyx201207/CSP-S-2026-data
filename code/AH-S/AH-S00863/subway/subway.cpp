//freopen froepen
//#define int long long signed main()
//Oct31==Dec25?
//O((m + q) * w^2 + n^3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL MAXN = 505, MAXM = 500005, INF = 0x3F3F3F3F3F3F3F3F;
LL C, N, M, D, Q, K, A, T;
LL Weight[MAXM];
vector<pair<LL, LL> > Stations[MAXM];
LL Dis[MAXN][MAXN];
void Init() {
	memset(Dis, 0x3F, sizeof Dis);
	for(int i = 1; i <= N; i++) Dis[i][i] = 0;
}
void Input() {
	scanf("%lld%lld%lld%lld%lld", &C, &N, &M, &D, &Q);
	for(int i = 1; i <= M; i++) {
		scanf("%lld", &Weight[i]);
	}
	Init();
	for(int i = 1; i <= N; i++) {
		cin >> K;
		for(int j = 1; j <= K; j++) {
			scanf("%lld%lld", &A, &T);
			Stations[A].emplace_back(i, T);
		}
	}
}
void Preset() {
	for(int i = 1; i <= M; i++) {
		for(auto [Line1, Time1] : Stations[i]) {
			for(auto [Line2, Time2] : Stations[i]) {
				Dis[Line1][Line2] = min(Dis[Line1][Line2], Time1 + Time2);
			}
		}
	}
}
void Floyd() {
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
			}
		}
	}
}
LL SolveEach(LL Start, LL End) {
	LL Ans = INF;
	for(auto [Line1, Time1] : Stations[Start]) {
		for(auto [Line2, Time2] : Stations[End]) {
			Ans = min(Ans, Time1 + Dis[Line1][Line2] + Time2);
		}
	}
	return Ans + Weight[Start] + Weight[End];
}
void Solve() {
	for(int i = 1; i <= Q; i++) {
		LL Start, End; cin >> Start >> End;
		printf("%lld\n", SolveEach(Start, End));
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Input();
	Preset();
	Floyd();
	Solve();
	return 0;
}