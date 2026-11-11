#include<bits/stdc++.h>
using namespace std;
vector<int> a[500005],t[500005];
int dis[3005][3005],w[500005],c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(i!=j) dis[i][j]=dis[j][i]=1e9;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
		for(int sb=0;sb<k;sb++) for(int bs=0;bs<k;bs++){
			dis[a[i][sb]][a[i][bs]]=dis[a[i][bs]][a[i][sb]]=min(dis[a[i][sb]][a[i][bs]],t[i][sb]+t[i][bs]);
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) for(int k=1;k<=m;k++)
		dis[j][k]=dis[k][j]=min(dis[j][k],dis[i][j]+dis[i][k]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}
