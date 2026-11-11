#include <iostream>
using namespace std;

#ifdef DBG
#define dbg(x) cerr<<"@@ "<<__LINE__<<" : "<<#x<<" = "<<x<<'\n';
#else
#define dbg(x)
#endif

constexpr int N = 5 * 10e5 + 10;
constexpr int M = 3 * 10e5 + 10;
int a[N];
int res[M];
int n, m;

void Fill() {
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		int ai;
		cin>>ai;
		a[i]=ai;
	}
}

void Solve(int i) {
	for(int j=i;j<n;j++){
		dbg(j)
		dbg(a[j])
		for(int k=n-1;k>j;k--) {
			dbg(k)
			dbg(a[k])
			if (a[k]==a[j]) {
				j=k;
				break;
			}
		}
		res[a[j]-1]++;
		dbg("                    ")
	}
	dbg("------------------")
}

int main() {
#ifdef DBG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("card.in", "r", stdin); // <<<<<<<<<<<<<<<<<<<<<
	freopen("card.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Fill();
	for(int i=0;i<n;i++){
		Solve(i);
	}
	for(int i=0;i<m-1;i++){
		cout<<res[i]<<' ';
	}
	cout<<res[m-1];
	return 0;
} 
