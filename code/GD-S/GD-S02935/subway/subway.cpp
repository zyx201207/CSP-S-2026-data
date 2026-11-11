#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,q,n,d,m,col[500005][505],k[505];
int kk[500005][25],a[505][500005],s,to;
ll t[500005][505],dis[505][505],w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];//线路i的第j个站台 
			cin>>t[i][j];//从线路i的第j个站台走到线路i的花费 
			col[a[i][j]][i]=j;//col[i][j]即为第i个站台是第j条线路的第几个 
			kk[a[i][j]][++kk[a[i][j]][0]]=i;//k[i][j]为站台i的第j条线路的实际编号 
		}
	}
	memset(dis,0x7f7f,sizeof dis);
	for(int i=1;i<=m;i++){//枚举站台 
		for(int j=1;j<=kk[i][0];j++){ 
			for(int it=1;it<=kk[i][0];it++){//j、it枚举线路 
				if(kk[i][j]!=kk[i][it]) dis[kk[i][j]][kk[i][it]]=min(dis[kk[i][j]][kk[i][it]],t[kk[i][j]][col[i][kk[i][j]]]+t[kk[i][it]][col[i][kk[i][it]]]);
				else dis[kk[i][j]][kk[i][it]]=0;
//				if(kk[i][j]!=kk[i][it]) cout<<kk[i][j]<<" "<<col[i][kk[i][j]]<<" "<<kk[i][it]<<" "<<col[i][kk[i][it]]<<" "<<t[kk[i][j]][col[i][kk[i][j]]]<<" "<<t[kk[i][it]][col[i][kk[i][it]]]<<"\n";
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int mid=i;mid<=j;mid++){
				dis[i][j]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		cin>>s>>to;
		ll ans=0,middle=dis[0][0];
		ans=w[s]+w[to];
		for(int j=1;j<=kk[s][0];j++){
			for(int it=1;it<=kk[to][0];it++){
				middle=min(middle,dis[kk[s][j]][kk[to][it]]+t[kk[s][j]][col[s][kk[s][j]]]+t[kk[to][it]][col[to][kk[to][it]]]);
			}
		}
		cout<<ans+middle<<"\n";
	}
	return 0;
}
