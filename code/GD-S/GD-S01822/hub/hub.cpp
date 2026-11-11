#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
typedef std::pair<int,int> pii;
using namespace std;
int n,k,u,v;
void solve(){
	cin>>n>>k;
	cerr<<(n-6)/8-k/4+2<<"\n";
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	fre("hub");
	int t;cin>>t>>t;
	while(t--) solve();
}

