#include<bits/stdc++.h>
using namespace std;
int w[1001],k[1001],a[1001][1001],di[1001][501],dis[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	//Test 1~11 44pts
	if(c<=11){
		memset(di,0x3f,sizeof(di));
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++)
			dis[i][i]=0;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int t;
				cin>>a[i][j]>>t;
				di[a[i][j]][i]=min(di[a[i][j]][i],t);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(int l=1;l<=k[i];l++)
					dis[a[i][j]][a[i][l]]=
					di[a[i][j]][i]+di[a[i][l]][i];
			}
		}
		for(int l=1;l<=m;l++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][l]+dis[l][j],dis[i][j]);
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			//cout<<dis[x][y]<<endl;
			printf("%d\n",w[x]+w[y]+dis[x][y]);
		}
	}
	return 0;
}
//miao ~
//++ RP
//RP ++
//44 pts
//All 144 pts
