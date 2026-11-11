#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()	
#define SZ(x) ((int)((x).size()))
#define Mod(x) ((x) % P)
#define ModE(x) ((x) %= P)
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using db = double;
constexpr int infI = 1 << 30;
constexpr ll infL = 1ll << 60;

const int N = 5e5 + 10;

int n;

ll m;

ll a[N];

ll sum[N];

int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	rep(i,1,n) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	rep(i,1,n) sum[i] = sum[i - 1] + a[i];
	rep(i,1,n){
		//all transform into a[i],the max answer
		int l = -1,r = i;
		while(l + 1 < r){
			int mid = (l + r) >> 1;
			// cerr << i << ' ' << l << ' ' << r << ' ' << mid << ' ' << (i - mid) * a[i] - (sum[i] - sum[mid]) << endl;
			// cerr << (i - mid) * a[i] - (sum[i] - sum[mid]) << endl;
			if((i - mid) * a[i] - (sum[i] - sum[mid]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans,i - r);
	}
	printf("%d\n",ans);
	return 0;
}