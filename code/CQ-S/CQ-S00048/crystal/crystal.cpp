#include<bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i,l,r) for(int i=(l); i<=(r); ++i)
#define drep(i,r,l) for(int i=(r); i>=(l); --i)
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,S=1,j=1,cur,a[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FASTIO;
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1); 
	rep(i,2,n) {
		cur+=(i-j)*(a[i]-a[i-1]);
		while(j<i&&cur>m) cur-=a[i]-a[j++];
		S=max(S,i-j+1);
	}
	cout<<S<<'\n';
}
