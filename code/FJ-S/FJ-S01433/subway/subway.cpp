#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005],k[505];
long long ans[500005];
vector<long long> a[505];
vector<long long> t[505];
vector<long long> mm[500005];
struct node {
	long long u,v,s,id;
} Q[100005];
bool cmp1(node x1,node x2) {
	if(x1.u==x2.u) return x1.id<x2.id;
	return x1.u<x2.u;
}
bool cmp2(node x1,node x2) {
	return x1.id<x2.id;
}
priority_queue<pair<long long,long long> ,vector<pair<long long,long long> > ,greater<pair<long long,long long> > > p;
//void dij(long long be){
//	p.push({0,be});
//	while(!p.empty()){
//		auto x=p.top();
//		p.pop();
//		if(x.first>ans[x.second]) continue;
//		long long s=x.first,u=x.second;
//		for(auto vi:mm[u]){
//			for(auto vj:a[vi]){
//				if(ans[vj]<ans[u]+t[vi][u]+t[vi][vj]) {
//					ans[vj]=ans[u]+t[vi][u]+t[vi][vj];
//					p.push({ans[vj],vj});
//				}
//			}
//		}
//	}
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	long long TT;
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			long long mj,mi;
			cin>>mj>>mi;
			a[i].push_back(mj);
			t[i].push_back(mi);
			TT=mi;
			mm[mj].push_back(i);
		}
	}
	for(int i=1; i<=q; i++) {
		cin>>Q[i].u>>Q[i].v;
		Q[i].id=i;
	}
	sort(Q+1,Q+1+n,cmp1);
	int flag=0,x=0;
	for(int i=1;i<=q;i++){
		if(Q[i].u!=x) flag=0,x=Q[i].u;
		if(flag==0){
			for(int i=1;i<=n;i++) ans[i]=w[i]+w[x];
			//dij(x);
		}
		Q[i].s=ans[Q[i].v];
	}
	sort(Q+1,Q+1+n,cmp2);
	for(int i=1;i<=q;i++) cout<<w[Q[i].u]+w[Q[i].v]+2*TT<<endl;
	return 0;
}
