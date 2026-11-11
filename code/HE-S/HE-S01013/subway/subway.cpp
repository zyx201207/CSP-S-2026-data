#include<bits/stdc++.h>
using namespace std; 
long long dis[905][905];
int cnt=0;
int near[54188];
long long a[35][35],t[35][35];//25线 25站 
long long c,m,n,d,q;//n=地铁线路数 
long long out[114514];//time 
long long zhan[35][35];//zhan[i][j]=第i站的第j个路线编号 
long long zhan_c[35];//zhan_c[i]=第i站有多少个路线
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=904;i++){
		for(int j=1;j<=904;j++)dis[i][j]=1e18;
	}
	
	for(int i=1;i<=m;i++)cin>>out[i];
	for(long long i=1;i<=n;i++){//第i条的第j个地铁站 
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cnt++;
			near[cnt]=a[i][j];
			cin>>t[i][near[cnt]];
			zhan_c[ a[i][j] ]++;
			zhan  [ a[i][j] ][ zhan_c[ a[i][j] ] ]=i;
		}
		for(int h=2;h<=cnt;h++){
			dis[ (i-1)*m+near[h] ][ (i-1)*m+near[h-1] ]=0;
			dis[ (i-1)*m+near[h-1] ][ (i-1)*m+near[h] ]=0;
		}
		memset(near,0,sizeof(near));
		cnt=0;
	}
	for(int i=1;i<=m;i++){//i站 第j,k条线路编号
		for(int j=1;j<=zhan_c[i];j++){
			for(int k=1;k<=zhan_c[i];k++){
				int idu=(zhan[i][j]-1)*m+i;
				int idv=(zhan[i][k]-1)*m+i;
				if(idu!=idv){
					dis[idu][idv]=t[zhan[i][j]][i]+t[zhan[i][k]][i];
					dis[idv][idu]=t[zhan[i][j]][i]+t[zhan[i][k]][i];
				}
			}
		}
	}
	
//	This is bufenfen n,m only <=30!!!!!!!!
//	ohno expect 20 pts
//	plz!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//	for(int i=1;i<=10;i++){
//		for(int j=1;j<=10;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n*m;k++){
		for(int i=1;i<=n*m;i++){
			for(int j=1;j<=n*m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 

	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		long long ans=2e18;
		for(int j=1;j<=n;j++){//qi de luxian
			for(int k=1;k<=n;k++){//zhong's luxian
				ans=min(ans,dis[(j-1)*m+u][(k-1)*m+v]+t[j][u]+t[k][v]);
			}
		}
		cout<<ans+out[u]+out[v]<<'\n';
	}
	return 0;
} 
