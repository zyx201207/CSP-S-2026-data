#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair<int,int>
#define mkp make_pair
#define pb push_back
#define vi vector<int>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define vsz(x) (int)x.size()
#define ll long long

bool MemoryST;

const int N=5e5+10;

ll n,m,a[N],s[N];

void Mainsolve() {
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int j=1,ans=0;
	rep(i,1,n) s[i]=s[i-1]+a[i];
	rep(i,1,n) {
		while(a[i]*(i-j+1)-s[i]+s[j-1]>m) ++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<"\n";
}

bool MemoryED;
int main() {
//	system("fc crystal.out crystal4.ans"); exit(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr<<fixed<<setprecision(6)<<(&MemoryST-&MemoryED)/1024.0/1024.0<<"MB\n";

	int T=1; //cin>>T;
	while(T--) Mainsolve();

	cerr<<"\n"<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}
