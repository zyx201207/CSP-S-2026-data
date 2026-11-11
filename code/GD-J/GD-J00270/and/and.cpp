#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
#define ull unsigned long long
#define pb push_back
#define ms(a) memset(a,0,sizeof a)
#define mss(a,b) memset(a,b,sizeof a)
#define msinf(a) memset(a,0x3f,sizeof a)
#define ppc __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define Pii pair<int,int>
#define fi first
#define se second
#define Fopen(in) freopen(in".in","r",stdin),freopen(in".out","w",stdout);
using namespace std;
constexpr int N=2e5+5,MOD=998244353;

int n,m,a[N];
void solve(){
	cin>>n>>m;
	For(i,1,n)
		cin>>a[i];
	vector<int> qwq;
	int ans=0;
	For(i,1,n)
		qwq.pb(a[i]);
	Fro(i,29,0){
		vector<int> pwp;
		int cnt=0;
		for(auto j:qwq)
			if(j>>i&1)
				cnt++,pwp.pb(j);
		if(cnt>=m)
			qwq=move(pwp),ans+=(1<<i);
	}
	cout<<ans;
}
signed main(){
	Fopen("and")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}