#include <iostream>
using namespace std;

#ifdef DBG
#define dbg(x) cerr<<"@@ "<<__LINE__<<" : "<<#x<<" = "<<x<<'\n';
#else
#define dbg(x)
#endif

constexpr int N = 2 * 10e5 + 10;
pair<int, char> a[N];
int n;

void Fill() {
	cin>>n;
	for(int i=0;i<n;i++){
		int rpt;
		char c;
		cin>>rpt>>c;
		a[i]=make_pair(rpt, c);
	}
}

int main() {
#ifdef DBG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("string.in", "r", stdin); // <<<<<<<<<<<<<<<<<<<<<
	freopen("string.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Fill();
	long long res = 0;
	pair<int, char>& acti = a[0];
	for(int i=0,j=n-1;;i++){
		if (i>=j)break;
		acti=a[i];
		dbg(i)
		dbg(acti.first)
		dbg(acti.second)
		while(acti.first>0) {
			pair<int, char>& cons = a[j];
			dbg(j)
			dbg(cons.first)
			dbg(cons.second)
			int toCons;
			dbg(toCons)
			if (acti.first<=cons.first) {
				toCons=acti.first;
			} else {
				toCons=cons.first;
			}
			
			acti.first -= toCons;
			cons.first -= toCons;
			if (acti.second != cons.second) {
				res+=toCons;
			}
			if(cons.first <= 0) j--;
			if(i>=j)break;
		}
	}
	cout << res;
	return 0;
} 
