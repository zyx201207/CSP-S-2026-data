#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,ma,qwq;
bool vis[N]; 
void dfs(int u,int sum) {
	if(u==m) {
		ans=max(ans,sum);
		return;
	} 
	for(int i=1;i<=n;++i) {
		if(vis[i]) continue;
		vis[i]=1;
		if(!u) dfs(u+1,a[i]);
		else dfs(u+1,sum&a[i]);
		vis[i]=0;
	}
}
signed main() {
	IOS
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	qwq=a[1];
	for(int i=1;i<=n;++i) cin >> a[i],ma=max(ma,a[i]),qwq&=a[i];
	if(n<=20) {
		dfs(0,0);
		cout << ans;
		return 0;
	}
	if(n<=2000) {
		if(m==1) {
			cout << ma;
			return 0;
		}
		if(m==n) {
			cout << qwq;
			return 0;
		}
		if(m==2) {
			for(int i=1;i<=n;++i) {
				for(int j=i+1;j<=n;++j) {
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout << ans;
			return 0;
		}
	}
	for(int i=1;i<=n;++i) ans=max(ans,qwq|a[i]);
	cout << ans;
	return 0;
}
