#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],dis[31][31],ans=1e9,w[500005];
vector<int> v[500005];//点i在哪些线路 
int t[500005][31];//站厅到站台 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;//c,n,m,d,q线路数.站数、地铁站最多几条线，问题数 
	for(int i=1;i<=m;i++){
		cin>>w[i];//口到厅 
	}
	for(int i=1;i<=n;i++){//线路 
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){//点 
			cin>>a[j];cin>>t[a[j]][i];
			for(int z=0;z<v[a[j]].size();z++){
				int zd=v[a[j]][z];
				dis[zd][i]=min(dis[zd][k],t[a[j]][zd]+t[a[j]][i]);
				dis[i][zd]=dis[zd][i];
			}
			v[a[j]].push_back(i);
		}
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				//if(dis[i][j]<100)cout<<i<<" "<<k<<" "<<j<<" "<<dis[i][j]<<" "<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	int x,y;
	for(int o=1;o<=q;o++){
		cin>>x>>y;
		ans=1e9;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int d1=v[x][i],d2=v[y][j];
				ans=min(ans,w[x]+t[x][d1]+dis[d1][d2]+t[y][d2]+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
