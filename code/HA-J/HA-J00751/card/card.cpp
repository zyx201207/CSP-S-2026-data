#include<bits/stdc++.h>
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=5e5+5,M=3e5+5;
vector<int> g[M];
int n,m;
int a[N],last[N],nxt[N],cnt[M],sum[M];
int t[M];
bool vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
		if(last[a[i]]) nxt[last[a[i]]]=i;
		last[a[i]]=i;
		cnt[a[i]]++;
	}
	int res=m;
	for(int i=n; i>=1; i--){
		if(vis[a[i]]) continue;
		for(auto t:g[a[i+1]]){
			g[a[i]].push_back(t);
		}
		g[a[i]].push_back(a[i]);
		res--; vis[a[i]]=1;
		if(res==0) break;
	}
	for(int i=1; i<=m; i++){
		for(auto k:g[i]){
			t[k]+=cnt[i];
		}
	}
	for(int i=1; i<=m; i++) printf("%d ",t[i]);
	return 0;
}

