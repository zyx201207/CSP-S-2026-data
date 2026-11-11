#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
#define fin(f) freopen(f,"r",stdin)
#define fout(f) freopen(f,"w",stdout)
#define fo(i,l,r) for(int i=(l);i<=(r);i++)
#define of(i,r,l) for(int i=(r);i>=(l);i--)
#define debug cerr<<"["<<__LINE__<<"] "
#define pb push_back
#define endl '\n'
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=2e6+5;
int n;ll d;
ll a[N];
int pos[N];
namespace Bruce {
	const int NN=5005;
	ll f[NN][NN];
	ll s[NN];
	int flag[NN];
	int dp(int bg) {
		int cnt=0;
		fo(i,1,n) flag[i]=0;
		fo(i,1,n) s[i]=0;
		fo(i,1,n) f[0][i]=0;
		f[0][bg]=1;
		fo(i,1,n) {
			fo(j,1,n) s[j]=s[j-1]+f[i-1][j];
			fo(j,1,n) f[i][j]=0;
			fo(j,bg,n) {
				int p=max(pos[j],bg);
				if(p<j) f[i][j]=s[j-1]-s[p-1];
				if(f[i][j]&&!flag[j]) {
					flag[j]=i;
					cnt++;
				}
			}
			if(cnt==n-bg) {
				int ans=0;
				fo(j,bg,n) if(f[flag[j]][j]==2) ans++;
				return ans;
			}
		}
		int ans=0;
		fo(j,bg,n) if(flag[j]&&f[flag[j]][j]==2) ans++;
		return ans;
	}
	void solve() {
		int ans=0;
		fo(i,1,n) ans+=dp(i);
		cout<<ans<<endl;
	}
}
//namespace SubtaskB {
//}
int main() {
	fin("migrate.in");fout("migrate.out");
	ios::sync_with_stdio(0);cin.tie(nullptr);
	int c,t;cin>>c>>t;
	while(t--) {
		cin>>n>>d;
		fo(i,1,n) cin>>a[i];
		fo(i,1,n) pos[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
		if(c<=10) Bruce::solve();
//		if(c==13||c==14) SubtaskB::solve();
	}
	return 0;
}