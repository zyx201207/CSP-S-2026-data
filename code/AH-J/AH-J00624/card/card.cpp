#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],ans[300005],h[300005],i,j;
bool b[300005],f[300005];
vector<int> g[500005];
queue<int> q;
int main(void) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=n-1,s[a[n]]=1;i>0;--i) {
		if(!b[a[i]]) b[a[i]]=true,g[a[i+1]].push_back(a[i]);
		++s[a[i]];
	}
	q.push(a[n]),f[a[n]]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		h[++j]=u;
		for(int v:g[u])
			if(!f[v]) f[v]=true,q.push(v);
	}
	for(i=j;i>0;--i) {
		ans[h[i]]=s[h[i]];
		for(int v:g[h[i]]) ans[h[i]]+=ans[v];
	}
	for(i=1;i<=m;++i) printf("%d ",ans[i]);
	return 0;
}
