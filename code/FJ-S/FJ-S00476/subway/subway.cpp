#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,kdt[405],t,a[405],b[405],w[405][405];
bool v[405],f=true;
queue<int> l;
void bfs(){
	l.push(1);
	while(!l.empty()){
		int now=l.front();
		l.pop();
		for(int i=1;i<=m;i++){
			if(w[now][i]&&!v[i]){
				v[i]=true;
				l.push(i);
				for(int j=1;j<=m;j++) if(w[j][now]&&v[j]) w[j][i]=w[i][j]=w[j][now]+w[i][now];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>kdt[i];
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=1;j<=t;j++) cin>>a[j]>>b[j];
		for(int j=1;j<t;j++){
			for(int k=j+1;k<=t;k++){
				if(w[j][k]) w[j][k]=min(w[j][k],b[j]+b[k]);
				else w[j][k]=b[j]+b[k];
				if(w[k][j]) w[k][j]=min(w[k][j],b[j]+b[k]);
				else w[k][j]=b[j]+b[k];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) cout<<w[i][j]<<' ';
		cout<<'\n';
	}
	bfs();
	while(f){
		f=false;
		for(int i=1;i<m;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=m;k++){
					if(w[i][j]>w[i][k]+w[k][j]){
						w[i][j]=w[i][k]+w[k][j];
						f=true;
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x][y]+kdt[x]+kdt[y]<<'\n';
	}
	return 0;
}
