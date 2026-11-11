#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int M=5e5+5,N=505,Q=1e5+5;
int c,n,m,d,q;
int w[M],k[N];
//struct edge {
//	int ni,wi;
//};
//map<int ,int > a[N];
//map<int ,int > t[N];
//map<int ,int > vis[N];
//int cnt=0;
//map<int ,edge> v;
//map<edge,int > head;
//map<int ,int > wb;
//map<int ,int > nxt;
//
//void add(edge uu,edge vv,int ww) {
//	v[++cnt]=vv;
//	wb[cnt]=ww;
//	nxt[cnt]=head[uu];
//	head[uu]=cnt;
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("r","subway.in",stdin);
	freopen("w","subway.out",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		if(k[i]==1) {
			n--;
			i--;
			continue;
		}
//		cin>>a[i][1]>>t[i][1];
//		for(int j=2; j<=k[i]; j++) {
//			cin>>a[i][j]>>t[i][j];
//			edge p;
//			int www;
//			p.ni =i;
//			cin>>p.wi ;
//			cin>>www;
//			add()
//		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<w[x]*(w[y]-1);
	}
	return 0;
}
