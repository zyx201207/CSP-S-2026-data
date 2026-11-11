#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define rep(i,l,r) for(ri i=l;i<=r;i++)
#define per(i,r,l) for(ri i=r;i>=l;i--)
#define inl inline
signed main(){
  freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c, t;
	cin >> c >> t;
	srand(time(0));
	while(t --){
		cout << rand() % 5 + 1 << endl;
	}
	return 0;
}

