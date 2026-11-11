#include<bits/stdc++.h>
using namespace std;
const int N=505;const int M=5e5+5;
int c,n,m,D,q,d[M],o[M],TO[M],W[M],n1;bool bj[M];
struct node{int to,w;};
vector<node> g[N];
int dfs(int u,int t,int val) {
	if(u==t) return val;
	int cnt=0x3f3f3f3f;
	for(auto v:g[u]) {
		if(!bj[v.to]) {
			bj[v.to]=1;
			cnt=min(cnt,dfs(v.to,t,val+o[u]+v.w));
			bj[v.to]=0;
		}
	} 
	return cnt;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;++i)cin>>d[i];
	for(int i=1;i<=n;++i) {
		cin>>n1;
		for(int j=1;j<=n1;++j) cin>>TO[j]>>W[j];
		for(int j=1;j<=n1;++j)
			for(int k=1;k<=n1;++k) 
				if(TO[j]!=TO[k])
					g[TO[j]].push_back({TO[k],W[k]});
				else o[TO[j]]=W[k];
	}
	while(q--) {
		int x,y;cin>>x>>y;
		cout<<dfs(x,y,d[x])+d[y]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
