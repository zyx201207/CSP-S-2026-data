#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=(m);++i)
#define rev(i,n,m) for(int i(n);i>=(m);--i)
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int to[N],siz[N],cnt[M],a[N],lst[M],w[N],deg[N];
queue<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		cin>>a[i];
		lst[a[i]]=i;
	}
	rep(i,1,n){
		to[i]=lst[a[i]]+1;
		w[i]=a[i];
		++deg[to[i]];
	}
	rep(i,1,n){
		if(!deg[i]) q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		if(u>n) break;
		int v=to[u];
		++siz[u];
		--deg[v];
		cnt[w[u]]+=siz[u];
		siz[v]+=siz[u];
		if(deg[v]==0) q.push(v);
	}
	rep(i,1,m) cout<<cnt[i]<<" ";
	return 0;
}
