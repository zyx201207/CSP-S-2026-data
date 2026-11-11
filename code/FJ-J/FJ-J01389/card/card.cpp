#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
struct node {
	int l,r;
};
int n,m,tot;
int a[N],pos[M],now;
int mp[N],ans[M];
node nd[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int id=1;id<=n;id++) {
		tot=0;
		memset(pos,0,sizeof(pos));
		memset(mp,0,sizeof(mp));
		for(int i=id;i<=n;i++) {
			if(pos[a[i]]) nd[++tot]={pos[a[i]],i},mp[pos[a[i]]]=tot;
			pos[a[i]]=i;
		}
		now=id;
		while(now<=n) {
			ans[a[now]]++;
			while(mp[now]) now=nd[mp[now]].r;
			now++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
// csp-j 2026 1=
// 求求了，给我1=吧 
