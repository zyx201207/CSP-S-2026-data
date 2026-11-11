#include <fstream>
using namespace std;

ifstream fin("crystal.in");
ofstream fout("crystal.out");
#define cin fin
#define cout fout

typedef long long ll;
const ll N = 5e5+10;
ll a[N];
ll sum[N];

// 算了算了，只考虑特殊性质A和B 
int main() {
	ll n,m; cin>>n>>m;
	for (ll i=1; i<=n; ++i) {
		cin>>a[i];
	}
	for (ll i=1; i<=n; ++i) {
		sum[i] = sum[i-1]+i;
	}
	ll cha = a[2]-a[1];
	ll i;
	for (i=1; i<=n; ++i) {
		if (sum[i-1]*cha > m) {
			break;
		}
	}
	if (i>n) i=n;
	cout<<i<<'\n';
	return 0;
}
