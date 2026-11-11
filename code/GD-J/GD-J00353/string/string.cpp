#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i <= (b);i ++)
#define per(i,a,b) for(int i = a;i >= (b);i --)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5,INF=1e18;
int n,a[N],b[N],ans;
char c[N],d[N];
void Solve() {
	cin >> n;
	rep(i,1,n) cin >> a[i] >> c[i],b[n-i+1]=a[i],d[n-i+1]=c[i];
	rep(i,1,n+1) a[i]+=a[i-1],b[i]+=b[i-1];
	int A=0,B=0;
	while(A!=n||B!=n) {
		if(a[A]<b[B]) ans+=(min(a[A+1],b[B])-a[A])*(c[A+1]!=d[B]),A++;
		else ans+=(min(a[A],b[B+1])-b[B])*(c[A]!=d[B+1]),B++;
	}
	cout << ans/2;
	return ;
}
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int dc=0,T=1;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0;
}

