#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>

using namespace std;
typedef long long Long;
typedef unsigned long long ULong;
struct BfsData{
	int p, d;
};
struct DequeData{
	int end, d;
	
	friend inline bool operator < (const DequeData& a, const DequeData& b){
		if(a.end != b.end) return a.end < b.end;
		return a.d < b.d;
	}
	friend inline bool operator > (const DequeData& a, const DequeData& b){
		if(a.end != b.end) return a.end > b.end;
		return a.d > b.d;
	}
};

const int N = 2000000;
const int M = 300000;
const int INF = 0x3f3f3f3f;
const Long MOD = 998244353; 

int testdata_number;

int n; Long god;
Long x[N+1];
int pos[N+1];
int qmin[N+1];
int qcnt[N+1];
map<DequeData, int> opt;

inline void optInsert(int end, int d, int cnt){
	DequeData key = DequeData({end, d});
	map<DequeData, int>::iterator itr = opt.find(key);
	if(itr == opt.end()) opt.insert(make_pair(key, cnt));
	else itr->second += cnt;
}
inline void optApply(int p){
	while(!opt.empty() && opt.begin()->first.end <= p) opt.erase(opt.begin());
	qmin[p] = opt.begin()->first.d;
	qcnt[p] = opt.begin()->second;
}

inline void getansOn3(){
	Long ans = 0;
	for(int l = 1; l <= n; ++l){
		fill(qmin+l, qmin+n+1, INF);
		fill(qcnt+l, qcnt+n+1, 0);
		
		qmin[l] = 0, qcnt[l] = 1;
		
		for(int p = l; p <= n; ++p){
			int d = qmin[p];
			int end = pos[p];
			 
			for(int i = p+1; i < end; ++i){
				int insertd = d+1;
				if(qmin[i] > insertd){
					qmin[i] = insertd;
					qcnt[i] = 0;
				}
				if(qmin[i] == insertd){
					qcnt[i] += qcnt[p];
				}
			}
			if(qcnt[p] == 2) ++ans; 
		}
	}
	cout << ans << '\n';
}
inline void getansOn2logn(){
	Long ans = 0;
	for(int l = 1; l <= n; ++l){
		fill(qmin+l, qmin+n+1, INF);
		fill(qcnt+l, qcnt+n+1, 0);
		
		opt.insert(make_pair(DequeData({n+1, 0}), 1));
		
		for(int p = l; p <= n; ++p){
			int end = pos[p];
			
			optApply(p);
			int d = qmin[p];
			optInsert(end, d+1, qcnt[p]);
			
			if(qcnt[p] == 2) ++ans;
		}
	}
	cout << ans << '\n';
}

inline void solve(){
	cin >> n >> god;
	
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	for(int i = 1; i <= n; ++i){
		pos[i] = upper_bound(x+i, x+n+1, x[i] + god) - x;
	}
	
	if(n <= 200){
		getansOn3();
	}else{
		getansOn2logn();
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int t; cin >> testdata_number >> t; while(t--)
	{
		solve();
	}

	return 0;
}
