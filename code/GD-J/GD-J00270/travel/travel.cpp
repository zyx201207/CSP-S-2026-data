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

int row(char a){
	if('A'<=a && a<='C')
		return 1;
	return 2;
}
void solve(){
	int c1,c2,s1,s2;
	char ch1,ch2;
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	string ans(4,'0');
	if(c1==c2){
		ans[0]='1';
		if(s1==s2){
			ans[1]='1';
			if(row(ch1)==row(ch2)){
				ans[2]='1';
				if(abs(ch1-ch2)==1)
					ans[3]='1';
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	Fopen("travel")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}