#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200006;
typedef unsigned long long ull;
ull a[MAXN]; 
ull ___and(ull x,ull y){
	if (x == y) return x;
	bool w[MAXN];
	memset(w,0,sizeof(w));
	long long int wei = 0;
	while (x && y){
		
		bool tmpx = x % 2;
		bool tmpy = y % 2;
		if(tmpx == tmpy) w[wei] = 1;
		else w[wei] = 0;
		wei++;
		x /= 2;
		y /= 2;
	}
	long long int rw = 1;
	ull ans = 0;
	for(int i = 0; i <= wei; i++){
		if (w[i] == 1) ans += rw;
		rw *= 2;
	}
	return ans;
}
const long long INF = 1e18;
bool chc[MAXN];
long long ans[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] > ans[1]) ans[1] = a[i];
	}
	chc[ans[1]] = 1;
	if(m == 1) {
		cout << ans[1] << endl;
		return 0;
	}
	for(int i = 2; i <= m;i++){
		for(int j = 1; j <= n; j++){
			if(___and(ans[i - 1],a[j]) > ans[i]){
				if(!chc[a[j]]){
					ans[i] = ___and(ans[i - 1],a[j]);
					chc[a[j]] = 1;
				}
			}
		}
	}
	cout << ans[m];
	return 0;
}
