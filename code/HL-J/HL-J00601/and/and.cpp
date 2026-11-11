#include <iostream>
#define int long long
using namespace std;
int a[200010];
bool vis[200010];
int ans=0;
int n,m;
int b=-1;

void dfs(int x) {
	if (x>m) {
		ans=max(ans,b);
		//cout<<b<<endl;
		return;
	}
	for (int i=1;i<=n;i++) {
		if (vis[i]) continue;
		vis[i]=1;
		int t=b;
		//cout<<b<<' ';
		b=(b==-1?a[i]:b&a[i]);
		//cout<<b<<endl;
		dfs(x+1);
		b=t;
		vis[i]=0;
	}
	return;
}


void solve() {
    cin>>n>>m;
    //cout<<(n&m)<<endl;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
	}
	dfs(1);
	cout<<ans;
    return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}
