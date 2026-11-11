#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,p,x,y;
long long ds[505][505],w[500005],as;
struct nm{
	int to;
	long long vl;
};
vector<nm>v[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ds[i][j]=1e18;
		}
		ds[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			int py=v[i][j].to;
			long long pd=v[i][j].vl;
			for(int k=0;k<j;k++){
				ds[py][v[i][k].to]=min(ds[py][v[i][k].to],pd+v[i][k].vl);
				ds[v[i][k].to][py]=ds[py][v[i][k].to];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ds[j][k]=min(ds[j][k],ds[j][i]+ds[i][k]);
			}
		}
	}
	while(q--){
		cin>>x>>y,as=1e18;
		for(int i=0;i<v[x].size();i++){
			int py=v[x][i].to;
			long long pd=v[x][i].vl;
			for(int j=0;j<v[y].size();j++){
				as=min(as,w[x]+w[y]+pd+v[y][j].vl+ds[py][v[y][j].to]);
			}
		}
		cout<<as<<"\n";
	}
	return 0;
}
