#include<iostream>
#include<algorithm>
auto III = freopen("crystal.in", "r", stdin);
auto OOO = freopen("crystal.out", "w", stdout);
auto SSS = std::cin.tie(0) -> sync_with_stdio(0);
#define LL long long
#define RNG(x,l,r) &(x)[l], 1 + &(x)[r]
#define rep(i,l,r) for(int i = (l), i##_ = (r); i <= i##_; i++)
void tomax(auto&x, auto&&y){ if(y > x) x = y; }
using namespace std; namespace __{

#define int LL
constexpr int N = 2e6 + 5;
int n,m;
int a[N],s[N];

void main(){
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	sort(RNG(a,1,n));
	rep(i,1,n) s[i] = s[i-1] + a[i];
	int ans = 0;
	rep(i,1,n){
		int l = 1, r = i, res = -1;
		while(l <= r){
			int mid = (l + r) >>1;
			int cur = s[i] - s[mid - 1];
			int tar = a[i] * (i - mid + 1);
			if(tar - cur <= m) res = mid, r=mid-1; else l=mid+1;
		}
		// cout << i << ": " << res << endl;
		// if(i - res + 1 == 4998){
		// 	cout<<i<<' '<<res<<endl;
		// }
		tomax(ans, i - res + 1);
	}
	cout << ans << '\n';
}}
signed main(){ __::main(); }
