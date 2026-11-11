#include<bits/stdc++.h>
using namespace std;
//subway
int c,n,m,d,q,x,y;
long long ti;
long long w[500500];
int a[550][500500];
int cnt[500500];
int ve[500500][30];
long long t[500500][30];
long long dis[550][550];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e14;
		}
	}
	//n  线路
	//m  地铁站
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++){
			cin>>a[i][j]>>ti;
			ve[a[i][j]][++cnt[a[i][j]]]=i;
			t[a[i][j]][cnt[a[i][j]]]=ti;
			//a[i][j]  地铁站 
			//t[i][j]  时间 
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){//地铁站 
		for(int u=1;u<cnt[i];u++){//线路
			for(int v=u+1;v<=cnt[i];v++){//线路 
				dis[ve[i][u]][ve[i][v]]=min(dis[ve[i][u]][ve[i][v]],t[i][u]+t[i][v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=min(dis[i][j],dis[j][i]);
				dis[i][j]=dis[j][i];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" : "<<dis[i][j]<<endl;
//		}
//	}
	long long ans;
	for(int i=1;i<=q;i++){
		cin>>x>>y;//地铁站 
		ans=1e14;
		for(int u=1;u<=cnt[x];u++){
			for(int v=1;v<=cnt[y];v++){
				ans=min(ans,dis[ve[x][u]][ve[y][v]]+t[x][u]+t[y][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

