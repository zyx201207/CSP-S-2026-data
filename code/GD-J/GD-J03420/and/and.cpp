#include <iostream>
#include <algorithm>
using namespace std;

#ifdef DBG
#define dbg(x) cerr<<"@@ "<<__LINE__<<" : "<<#x<<" = "<<x<<'\n';
#else
#define dbg(x)
#endif

constexpr int N = 2 * 10e5 + 10;
long long a[N];
int n, m;

void Fill() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int ai;
		cin>>ai;
		a[i]=ai;
	} 
} 

int main() {
#ifdef DBG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("and.in", "r", stdin); // <<<<<<<<<<<<<<<<<<<<<
	freopen("and.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Fill();
	sort(a, a + N, greater<long long>{});
	long long res = a[0];
	dbg(n)
	dbg(m)
	dbg(a[0])
	for(int i=1;i<m;i++){
		dbg(a[i])
		res &= a[i];
	}
	cout<<res;
	return 0;
} 
