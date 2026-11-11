#include <bits/stdc++.h>
using namespace std;
const int N=200002;
int n,m,a[N],ans;
bool k[N][32],vis[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		int j=30;
		int t=a[i];
		while (t) {
			if (t%2==1) k[i][j]=1;
			t/=2;
			j--;
		}
	}
	for (int i=1;i<=30;i++) {
		int sum=0;
		for (int j=1;j<=n;j++) if (vis[j]==0 && k[j][i]==1) sum++;
		if (sum<m) continue;
		for (int j=1;j<=n;j++) if (k[j][i]==0) vis[j]=1;
	}
	ans=(1<<30)-1;
	for (int i=1;i<=n;i++) if (vis[i]==0) ans&=a[i];
	cout<<ans;
	return 0;
}
