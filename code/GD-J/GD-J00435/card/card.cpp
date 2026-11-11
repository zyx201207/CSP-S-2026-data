#include <bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->ios::sync_with_stdio(0);
using namespace std;
const int N=5e5+5;
struct Node {
	int pos,i;
} pre[N];
int n,m,a[N],t[N],tot,cnt[N];
bool vis[N];
signed main() {
	IOS
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=1;i<=n;++i) {
		memset(t,0,sizeof(t)),memset(pre,0,sizeof(pre)),tot=0;
		for(int j=i;j<=n;++j) {
			if(pre[a[j]].pos) {
				tot=pre[a[j]].pos;
				
				continue;
			}
			t[++tot]=a[j];
			pre[a[j]].pos=tot;
			pre[a[j]].i=i;
		}
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=tot;++j) vis[t[j]]=1;
		for(int j=1;j<=m;++j) cnt[j]+=vis[j];
	}
	for(int i=1;i<=m;++i) cout << cnt[i] << ' ';
	return 0;
}
