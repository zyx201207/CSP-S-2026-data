#include <bits/stdc++.h>
#define fs first
#define sc second
#define int long long
#define vi vector<int>
#define For(i,x,y) for(int i = x;i <= y;i ++)
#define For_(i,x,y) for(int i = x;i <= y;i ++)
#define pb push_back
#define endl '\n'
#define x0 _x0_
#define y1 _y1_
const int N = 5000 + 5;

using namespace std;
void gmax(int &x,int y) {
	x = max(x,y);
	return ;
}
int n,d,a[N];
int f[N][N];
int g[N][N];
void solve1(){
	cin >> n >> d;
	For(i,1,n) cin >> a[i];
	int ans = 0;
	For(i,1,n) {
		int it = i;
		int it2 = i;
		f[i][i] = 0,g[i][i] = 1;
		For(j,i + 1,n){
			while(it <= j && a[it] + d < a[j]) ++ it;
			it2 = max(it2,it);
			while(it2 < j && f[i][it2] == f[i][it]) ++ it2;
			f[i][j] = f[i][it] + 1;
			g[i][j] = g[i][it] * (it2 - it);
			ans += g[i][j] == 2;
//			if(g[i][j] == 2) cout << i << ' ' << j<< ' ' << it << ' ' << it2 << endl;
		}
	}
	cout << ans << endl;

}
namespace spe{
	const int N = 1e6+5;
	int a[N];
	int n,d;
	void solve2(){
		cin >> n >> d;
		For(i,1,n) cin >> a[i];
		int cnt = a[2] - a[1];
		cnt = d / cnt;
		int ans = 0;
		For(i,1,n-1) {
			int tmp = n - i;
			tmp /= cnt;
			ans+=max(0ll,tmp - 1);
		} cout << ans << endl;
	}

}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T = 1;
	int c=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c;

	cin >> T;
	while(T--) {
		if(c >= 11 && c <= 12 ) {
			spe::solve2();
		}else solve1();
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

*/
