#include<bits/stdc++.h>
using namespace std;
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],lst[M],sum[M],ans[M];
int head[M],nxt[M],to[M],deg[M],cnt;
void add(int u,int v){nxt[++cnt] = head[u],to[cnt] = v,deg[v]++,head[u] = cnt;}
int main(){
	fre("card");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> a[i],lst[a[i]] = i,sum[a[i]]++;
	for(int i = 1;i<=m;i++){
		if(lst[i]==n) continue;
		add(a[lst[i]],a[lst[i]+1]);
	}
	queue<int> q;
	for(int i = 1;i<=m;i++){
		if(!deg[i]) q.push(i);
		ans[i] = sum[i];
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int e = head[u],v;e;e = nxt[e]){
			v = to[e];
			deg[v]--;
			ans[v]+=ans[u];
			if(!deg[v]) q.push(v);
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i];
		if(i!=m) cout << " ";
	}
	return 0;
}
