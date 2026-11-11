#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i = a;i <= (b);i ++)
#define per(i,a,b) for(int i = a;i >= (b);i --)
#define pii pair<int,int>
#define fi first
#define se second
const int N=205,INF=1e18;
string c,s,cc,ss;
int C[N],t[N][N];
void Solve() {
	cin >> c >> s >> cc >> ss;
	C['D']=C['F']=1,t['A']['C']=t['C']['A']=1;
	if(c==cc) {
		if(s[0]==ss[0]&&s[1]==ss[1]) {
			if(C[s[2]]==C[ss[2]]) {
				if(C[s[2]]==1||t[s[2]][ss[2]]==0) cout << "1111";
				else cout << "1110";
			} else cout << "1100";
		} else cout << "1000";
	} else cout << "0000";
	return ;
}
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int dc=0,T=1;
	if(dc) cin >> T;
	rep(i,1,T) Solve();
	return 0;
}
