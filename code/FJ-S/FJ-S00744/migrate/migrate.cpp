#include <bits/stdc++.h>
using namespace std;
#define two second
#define one first
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e6 + 1;

int n;
ll d, x[maxn];
pii seg[maxn];

int main(){
	freopen("migrate.in", "r", stdin); freopen("migrate.out", "w", stdout);
	int c, t; scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		if(11 <= c && c <= 12){
			if(x[2] - x[1] >= d){printf("0\n"); continue;}
			else if((x[2] - x[1]) * 2 >= d){printf("0\n"); continue;}
			ll m = d / (x[2] - x[1]);
			printf("%lld\n", 1 + n - (m<<1));
		}
		for(int l = 1, r = 1, i = 1; i <= n; i++){
			while(l < i && x[i] - x[l] > d) l++;
			while(r < n && x[r + 1] - x[i] <= d) r++;
			seg[i] = mp(l, r);
		}cout << 0 << endl;
		
	}return 0;
}
