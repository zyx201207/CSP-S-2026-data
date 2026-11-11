#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,w[M],a[505][505],t[505][505],k[505];
int adj[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int x=1,y=1;
			while(a[i][x]!=a[j][y]&&x<=k[i]&&y<=k[j]){
				if(a[i][x]<a[j][y]){
					x++;
				}else{
					y++;
				}
			}
			if(a[i][x]==a[j][y])adj[i][j]=adj[j][i]=a[i][x];
		}
	}
	while(q--){
		bool ok=false;
		vector<int>v0,v1;
		int u,v;
		cin>>u>>v;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==u)v0.push_back(i);
				if(a[i][j]==v)v1.push_back(i);
			}
		}
		for(int i=0;i<v0.size();i++){
			for(int j=0;j<v1.size();j++){
				if(adj[v0[i]][v1[j]]!=0){
					cout<<w[u]+w[v]+4*t[1][1]<<endl;
					break;
				}
				if(v0[i]==v1[j]){
					cout<<w[u]+w[v]+2*t[1][1]<<endl;
					break;
				}
			}
		}
	} 
	return 0;
}
