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

struct Node{
	int p;
	char c;
}a[N];
int n,ans;
void solve(){
	cin>>n;
	For(i,1,n)
		cin>>a[i].p>>a[i].c;
	int i=1,j=n;
	while(i<j){
		while(a[j].p<=a[i].p && i<j){
			a[i].p-=a[j].p;
			if(a[j].c!=a[i].c)
				ans+=a[j].p;
			j--;
		}
		while(a[i].p<=a[j].p && i<j){
			a[j].p-=a[i].p;
			if(a[j].c!=a[i].c)
				ans+=a[i].p;
			i++;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	Fopen("string")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}