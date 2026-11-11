#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,q;//！？60分？！ 
int w[500005],a[500005],t[500005],dis[2005][2005];
void Floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)continue;
				if(dis[i][j]>dis[i][k]+dis[j][k]){
					dis[i][j]=dis[i][k]+dis[j][k];
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
//		cout<<w[i]<<endl;
	}
	memset(dis,0x3f,sizeof(dis));
	if(c<=11){
		for(int i=1;i<=n;i++){
			int ki;
			cin>>ki;
			for(int j=1;j<=ki;j++)cin>>a[j]>>t[j];
			for(int j=1;j<=ki;j++){
				for(int l=j+1;l<=ki;l++){
					dis[a[j]][a[l]]=min(dis[a[j]][a[l]],t[j]+t[l]);
					dis[a[l]][a[j]]=min(dis[a[l]][a[j]],t[j]+t[l]);
				}
			}
		}
		Floyd();
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<endl;
		}
	}else{
		int cnt;
		for(int i=1;i<=n;i++){
			int ki;
			cin>>ki;
			for(int j=1;j<=ki;j++)cin>>a[j]>>t[j];
		}
		cnt=t[1];
//		for(int i=1;i<=m;i++)cout<<w[i]<<' ';
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<cnt*2+w[x]+w[y]<<endl;
		}
	}
	
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//差一步美满
