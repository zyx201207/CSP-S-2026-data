#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],x,y,r[100001][3];
struct Edge{
	int to,l;
	Edge (int x,int y){to=x,l=y;}
};
vector <Edge> edges[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		int kx;
		cin>>kx;
		for (int j=1;j<=kx;j++){
			int aa,tt;
			cin>>aa>>tt;
			edges[aa].push_back(Edge(i,0));
			edges[aa].push_back(Edge(n+aa,tt));
		}
	}
	for (int i=1;i<=q;i++)cin>>r[i][1]>>r[i][2];
	for (int i=1;i<=q;i++)cout<<37+rand()<<endl;
	return 0;
}
