#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,pair<int,int> >
const int N=510;
const int M=5e5+10;
int h[N],ne[M],e[M],cnt;
int g[N][N];
int w[M],k[N];
int a[N][M],t[N][M];
int n,m,d,q,c;
void dij(int n){
	priority_queue<pii,vector<pii>,greater<pii>>Q;
}
void init(){
	for(int i=1;i<=n;i++){
		dij(i);
	}
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	init();
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<g[min(a,b)][max(a,b)]+w[a]+w[b]<<'\n';
	}
}
