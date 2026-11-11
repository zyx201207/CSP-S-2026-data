//T2 subway
#include<bits/stdc++.h>
using namespace std;
const int diff=0x3f3f3f3f;
int c,n,m,d,q;
int a[910][910];
int dis[910][910];
int ans;
int w[500050];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	if(c<=8){
		for(int i=1;i<=m;i++)scanf("%d",w+i);
		int ima[500050],imt[500050];
		for(int st=0;st<n;st++){
			int k;
			scanf("%d",&k);
			for(int j=0;j<k;j++)scanf("%d %d",ima+j,imt+j);
			for(int j=0;j<k;j++){
				for(int i=0;i<k;i++){
					if(i==j)continue;
					a[ima[i]][ima[j]]=imt[j];
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==0){
					dis[i][j]=diff;
					continue;	
				}
				if(a[i][j]==-1){
					dis[i][j]=0;
					continue;
				}
				dis[i][j]=a[i][j];
			}
		}
		for(int k=1;k<=m;k++){  //use Floyd to record the best role every stations
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(dis[i][k]!=diff&&dis[k][j]!=diff&&(dis[i][k]+dis[j][k])<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[j][k];
					}
				}
			}
		}
		int fr,to;
		while(q--){
			scanf("%d %d",&fr,&to);
			ans=w[fr]+w[to]+dis[fr][to]; //add time of walking to stations
			printf("%d\n",ans);
		}
	}
	return 0;
}
