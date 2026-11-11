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
constexpr int N=5e5+5,MOD=998244353;

int n,m,a[N],nxt[N],p[N],ans[N],res[N];
vector<int> f[N];
void solve(){
	cin>>n>>m;
	For(i,1,n){
		cin>>a[i];
	}
	Fro(i,n,1){
		if(p[a[i]])
			nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	For(i,1,n){
		if(nxt[i]!=0){
			int j=i;
			while(nxt[j]!=0){
				j=nxt[j];
			}
			res[j]++;
		}
		else{
			res[i]++;
			int j=i+1;
			res[j]+=res[i];
			while(nxt[j]!=0){
				j=nxt[j];
				res[j]+=res[i];
			}
			f[i].pb(a[i]);
		}
	}
	For(i,1,n)
		if(res[i])
			for(auto j:f[i])
				ans[j]+=res[i];
	For(i,1,m)
		cout<<ans[i]<<" ";
}
signed main(){
	Fopen("card")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}
// 11:10 ak
// red orange yellow yellow????
// feropen frepon forepen furry uid luogu 1210193 shellchen dsa orz ran qwq qaq sto shellchen
// 申请成为机房最晚 ak 之人
// cph-ng 强强？！？！
// 400pts thank you