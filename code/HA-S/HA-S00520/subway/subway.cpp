#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[5005],k[505],t2[505][5005],mp[505][5005],t[505][50005],sum,maxx,w1[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long x;
			cin>>x;
			cin>>t[i][x];//第i条线路的站点x从厅到站所需时间 
			t2[i][j]=x;//第i条线第j个站点是x 
			mp[0][x]++;//经过x站点的线路有几条 
			mp[mp[0][x]][x]=i;//经过x站点的线路是i 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			w1[i][j]=0x7fffffff;
		}
	}
	for(int i=1;i<=m;i++){//第i个站点 
		if(mp[0][i]>=2){
			for(int j=1;j<=mp[0][i];j++){//有mp[0][i]条线路经过i 
				for(int l=1;l<=k[mp[j][i]];l++){//第j条线路有l个站点
					if(i!=t2[mp[j][i]][l]){
						w1[i][t2[mp[j][i]][l]]=t[mp[j][i]][i]+t[mp[j][i]][t2[mp[j][i]][l]];
						w1[t2[mp[j][i]][l]][i]=t[mp[j][i]][i]+t[mp[j][i]][t2[mp[j][i]][l]];
					}
				}
			}
		}
	}
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				w1[i][j]=min(w1[i][j],w1[i][l]+w1[l][j]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		long long x,y;
		cin>>x>>y;
		cout<<w1[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
