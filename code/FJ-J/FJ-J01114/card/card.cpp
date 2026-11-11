#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int vis[N],cnt[N],last[N],ans[N],a[N],n,m;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		last[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++) {
		if(vis[a[i]]) continue;
		vis[a[i]]=1;
		int j=i;
		while(j<=n) {
			ans[a[j]]+=cnt[a[i]];
			j=last[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<ans[i]<<' ';
	}
	return 0;
}
