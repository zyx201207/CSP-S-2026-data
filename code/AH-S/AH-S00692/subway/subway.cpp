#include<bits/stdc++.h>
using namespace std;


int c,n,m,d,q;
int w[5005],k[505],a[505][5005],f[505][5005];
int g[5005][5005];
vector<int> hu[50005];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>f[i][j];
			hu[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(hu[i].size()==1)
			continue;
		for(int j=0;j<hu[i].size();j++){
			for(int k=j+1;k<hu[i].size();k++){
				g[hu[i][j]][hu[i][k]]=f[hu[i][j]][m]+f[hu[i][k]][m];
				g[hu[i][k]][hu[i][j]]=f[hu[i][j]][m]+f[hu[i][k]][m];
			}
		}
	}
	floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int sum=INT_MAX;
		for(int i=0;i<hu[x].size();i++){
			for(int j=i;j<hu[y].size();j++){
				sum=min(sum,g[hu[x][i]][hu[y][j]]);
			}
		}
		sum=sum+w[x]+w[y];
		cout<<sum<<"\n";
	}
	return 0;
}

