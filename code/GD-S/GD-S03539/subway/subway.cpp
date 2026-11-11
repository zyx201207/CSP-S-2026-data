#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long o,n,m,d,q,a[N],dist[N][N],w[N][N],b[N];
vector<int>c[30];
void f1(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<c[i].size();j++){
			for(int k=0;k<j;k++){
				dist[c[i][k]][c[i][j]]=min(dist[j][k],w[i][c[i][j]]+w[i][c[i][k]]);
				dist[c[i][j]][c[i][k]]=dist[c[i][k]][c[i][j]];
			}
		}
	}
}
void f2(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				dist[j][i]=dist[i][j];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>o>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	memset(dist,0x3f,sizeof dist);
	memset(w,0x3f,sizeof w);
	for(int i=1;i<=m;i++){
		dist[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=b[i];j++){
			int v,t;cin>>v>>t;
			w[i][v]=t;
			c[i].push_back(v);
		}
	}
	f1();
	f2();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+a[x]+a[y]<<endl;
	}
	return 0;
}
