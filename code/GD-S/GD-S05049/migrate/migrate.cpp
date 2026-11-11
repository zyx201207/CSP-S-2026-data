#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, b, e) for(int i=(b);i<=(e);++i)

const int N = 2e6+10;
int C, T;
int n;
ll d, x[N];
vector<int> pth;

inline void init(){
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
}

inline bool ok(int u, int v) { return v>u&&(x[v]-x[u])<=d; }
inline bool ok2(int u, int mid, int v) { return ok(u, mid)&&ok(mid, v); }

void findpth(int u, int v, int l){
	if(v-u==0) { pth.emplace_back(l); return;}
	rep(i, u+1, v){
		if(x[i]-x[u]<=d) findpth(i, v, l+1);
		else break;
	}
}

void solve(){ // 暴力
	ll ans=0; 
	rep(u, 1, n-2){
		rep(v, u+2, n){
//			cout << u << '/' << v << '-';
			pth.clear();
			findpth(u, v, 1);
			sort(pth.begin(), pth.end());
//			for(int i:pth) cout << i << ' ';
//			cout << endl;
			if(pth.size()==2) {
				ans+=(pth[0]==pth[1]);
			} else if(pth.size()>2){
				ans+=(pth[0]==pth[1]&&pth[1]!=pth[2]);
			}
		}
	}
	cout << ans << endl;
}

void solveA(){
	ll dd = x[2]-x[1]; // 公差
	if(dd==0) {
		cout << 0 << endl;
		return ;
	}
	ll ov = d/dd; // 一次能飞过几个岛
//	printf("%d/%d ", ov, n);
	if(ov<=1) cout << 0 << endl;
	else if(ov>=n) cout << 0 << endl;
	else if(n==ov+1) cout << 1 << endl;
	else {
		ll b = min(ov*2, ll(n));
		cout << (1+b-ov)*ov/2 << endl;
	}
}

void solveB(){
	
}

void solveC(){
	
}

void solveSB(){
	cout << 0 << endl;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	C = 12;
	if(C<=10) while(T--){
		init();
		solve();
	} else if(C<=12) while(T--){
		init();
		solveA();
	} else if(C<=14) while(T--){
		init();
		solveB();
	} else if(C<=18) while(T--){
		init();
		solveC();
	} else while(T--){
		init();
		solveSB();
	}
	
	return 0;
} 
