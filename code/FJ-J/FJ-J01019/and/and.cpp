#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m,ans;
bitset<N> vis,a[32];
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;cin>>x;
		for(int j=0;j<32;j++) {
			a[j][i]=x&1;x>>=1;
		}
	}
	for(int i=31;i>=0;i--) {
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(vis[j]) continue;
			cnt+=a[i][j];
		}
		if(cnt>=m) {
			for(int j=1;j<=n;j++) {
				if(vis[j]) continue;
				if(!a[i][j]) vis[j]=1;
			}
			ans+=1ll<<i;
		}
	}
	cout<<ans;
	return 0;
}
