#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i <= (b);i ++)
#define per(i,a,b) for(int i = a;i >= (b);i --)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5,INF=1e18;
int n,a[N],m,ans,x;
bool cmp(int a,int b) {return a>b;}
void Solve() {
	cin >> n >> m,x=1;
	rep(i,1,n) cin >> a[i];
	per(i,30,0) {
		if(x) sort(a+1,a+n+1,cmp),x=0;
		if(a[m]&(1<<i)) ans|=(1<<i);
		else {rep(j,1,n) a[j]|=(1<<i),a[j]^=(1<<i); x=1;}
	}
	cout << ans;
	return ;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int dc=0,T=1;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0;
}

