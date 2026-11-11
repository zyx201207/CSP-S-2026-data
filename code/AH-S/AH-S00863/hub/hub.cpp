//freopen froepen
//#define int long long signed main()
//Oct31==Dec25?
//trick A: 2/20 = 10pts(earned)
//O(2^n): 3/20 = 15pts(earned)
//k=2: 3/20=15pts(earned)
//O(n^2): 7/20 = 35pts
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr LL MAXN = 1000005, INF = 0x3F3F3F3F3F3F3F3F;
LL C, T;
LL N, K;
vector<LL> Tree[MAXN];
void Init() {
	for(int i = 1; i <= N; i++) {
		Tree[i].clear();
	}
}
void Input() {
	scanf("%lld%lld", &N, &K);
	Init();
	for(int i = 1; i < N; i++) {
		LL Node1, Node2;
		scanf("%lld%lld", &Node1, &Node2);
		Tree[Node1].push_back(Node2);
		Tree[Node2].push_back(Node1);
	}
}
void Solve1314() {
	LL NewN = N / 2 - K;
	LL Ans = (NewN + 3) / 4 + 1;
	printf("%lld\n", Ans);
}
namespace BruteForce{
	bool Flag[MAXN], DFSed[MAXN];
	void DFS(LL Node1, LL Previous) {
		DFSed[Node1] = true;
		for(auto Node2 : Tree[Node1]) {
			if(Node2 != Previous && Flag[Node2]) {
				DFS(Node2, Node1);
			}
		}
	}
	queue<LL> BFSQueue;
	LL Dis[MAXN];
	LL GetDis() {
		for(int i = 1; i <= N; i++) {
			Dis[i] = INF;
			if(Flag[i]) {
				Dis[i] = 0;
				BFSQueue.push(i);
			}
		}
		LL Ans = 0;
		while(!BFSQueue.empty()) {
			LL Node1 = BFSQueue.front();
			BFSQueue.pop();
			Ans = max(Ans, Dis[Node1]);
			for(auto Node2 : Tree[Node1]) {
				if(Dis[Node2] == INF) {
					Dis[Node2] = Dis[Node1] + 1;
					BFSQueue.push(Node2);
				}
			}
		}
		return Ans;
	}
	void Solve123() {
		LL Res = INF;
		for(int i = 0; i < (1 << N); i++) {
			if(__builtin_popcount(i) != K) continue;
			for(int j = 1; j <= N; j++) {
				if(i & (1 << (j - 1))) {
					Flag[j] = true;
				}else{
					Flag[j] = false;
				}
				DFSed[j] = false;
			}
			LL Cnt = 0;
			for(int j = 1; j <= N; j++) {
				if(!DFSed[j] && Flag[j]) {
					DFS(j, 0);
					Cnt++;
				}
			}
			if(Cnt > 2) continue;
			Res = min(Res, GetDis());
		}
		printf("%lld\n", Res);
	}
}
using namespace BruteForce;
namespace K2{
	vector<LL> Diameter;
	LL Prev[MAXN], Dep[MAXN], DN1, DN2;
	void DFS2(LL Node1, LL Previous) {
		Prev[Node1] = Previous;
		Dep[Node1] = Dep[Previous] + 1;
		for(auto Node2 : Tree[Node1]) {
			if(Node2 != Previous) DFS2(Node2, Node1);
		}
	}
	bool Check(LL Mid) {
		for(int i = 1; i <= N; i++) Flag[i] = false;
		Flag[Diameter[Mid]] = Flag[Diameter[Diameter.size() - 1 - Mid]] = true;
		return GetDis() <= Mid;
	}
	void StepI() {
		Diameter.clear();
		DFS2(1, 0);
		DN1 = 0;
		for(int i = 1; i <= N; i++) {
			if(Dep[i] > Dep[DN1]) DN1 = i;
		}
		DFS2(DN1, 0);
		DN2 = 0;
		for(int i = 1; i <= N; i++) {
			if(Dep[i] > Dep[DN2]) DN2 = i;
		}
		for(int Node = DN2; Node != 0; Node = Prev[Node]) {
			Diameter.push_back(Node);
		}
	}
	void SolveK2() {
		StepI();
		LL L = -1, R = (Diameter.size() - 1) / 2;
		while(L + 1 != R) {
			LL Mid = (L + R) / 2;
			if(Check(Mid)) R = Mid;
			else L = Mid;
		}
		printf("%lld\n", R);
	}
}
using namespace K2;
void Solve() {
	if(K == N) {
		printf("0\n");
		return;
	}
	if(C == 13 || C == 14) {
		Solve1314();
	}
	if(C <= 3) {
		Solve123();
	}
	if(C == 7 || C == 11 || C == 12) {
		SolveK2();
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &C, &T);
	for(int i = 1; i <= T; i++) {
		Input();
		Solve();
	}
	return 0;
}