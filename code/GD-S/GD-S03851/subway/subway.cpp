#include<bits/stdc++.h>
using namespace std;
struct c1{
	int v,t;
};
vector<c1>a[500001];
int c,n,d,q,m,w[500001];
long long f[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,127,sizeof(f));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int b,t;
			cin>>b>>t;
			a[b].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				int u=a[i][j].v,v=a[i][k].v,t=a[i][j].t+a[i][k].t;
				f[u][v]=f[v][u]=t;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]==f[0][0]||f[k][j]==f[0][0])continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ss=f[0][0];
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				int u=a[x][j].v,v=a[y][k].v,t=a[x][j].t+a[y][k].t;
				ss=min(ss,f[u][v]+t);
			}
		}
		cout<<ss+w[x]+w[y]<<'\n';
	}
	return 0;
}
