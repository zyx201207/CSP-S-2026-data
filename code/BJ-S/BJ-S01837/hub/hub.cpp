#include <bits/stdc++.h>
using namespace std;
vector<int>s[15];
int fa[15];
bool t[15];
bool t2[15];
int n,k;
int find(int x) {
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x);y=find(y);
	if (x!=y) fa[x]=y;
	return ;
}
int low=1000;
void dfs(int now,int pre,int st) {
	if (t[now]==1) {
		low=min(low,st);
		return ;
	}
	for (auto i:s[now]) {
		if (i!=pre) dfs(i,now,st+1);
	}
}
void solve() {
	cin>>n>>k;
	memset(t,0,sizeof(t));
	memset(fa,0,sizeof(fa));
	for (int i=1;i<=14;i++) s[i].clear();
	for (int i=1;i<=n-1;i++) {
		int x,y;
		cin>>x>>y;
		s[x].push_back(y);
		s[y].push_back(x);
	}
	int ans=1000,subans=0,tps=0;
	for (int i=1;i<(1<<n);i++) {
		int ks=i;
		int p=0;
		for (int j=1;j<=n;j++) {
			t[j]=(ks&1);
			ks>>=1;
			p+=t[j];
		}
		if (p!=k) continue;
		for (int j=1;j<=n;j++) fa[j]=j;
		for (int j=1;j<=n;j++) {
			if (t[j]==0) continue;
			for (auto l:s[j]) {
				if (t[l]==1) merge(l,j);
			}
		}
		memset(t2,0,sizeof(t2));
		for (int j=1;j<=n;j++) if (t[j]==1) t2[find(j)]=1;
		int cnt=0;
		for (int j=1;j<=n;j++) cnt+=t2[j];
		if (cnt>2) continue;
		subans=0;
		for (int j=1;j<=n;j++) {
			low=1000;
			if (t[j]==0) dfs(j,j,0);
			if (t[j]==0) subans=max(subans,low);
			//cout<<low<<'\n';
		}
		ans=min(ans,subans);
		tps++;
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	for (int i=1;i<=T;i++) {
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
