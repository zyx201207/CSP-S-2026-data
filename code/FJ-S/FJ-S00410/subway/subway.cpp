#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
int a[510][1010],t[20010][510];
int dis[12][12];
bool A=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	if(1<=c && c<=3){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>a[i][j];
				cin>>t[a[i][j]][i];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) dis[i][j]=-1;
				else dis[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=n;l++){
					if(t[i][l]>0 && t[j][l]>0){
						dis[i][j]=min(dis[i][j],t[i][l]+t[j][l]);
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					if(i!=j && i!=l && j!=l && dis[i][l]!=0x3f3f3f3f && dis[j][l]!=0x3f3f3f3f){
						
						dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
						dis[j][i]=dis[i][j];
						
					}
						
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<"\n";
		}
	}
	if(7<=c && c<=11){
		for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			if(k[i]==2){
				int a1,a2,t1,t2;
				cin>>a1>>t1>>a2>>t2;
				dis[a1][a2]=t1+t2;
				dis[a2][a1]=t1+t2;
			}
		}
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					if(i!=j && i!=l && j!=l && dis[i][l]!=0 && dis[j][l]!=0){
						if(dis[i][j]!=0){
							dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
							dis[j][i]=dis[i][j];
						}
						else{
							dis[i][j]=dis[i][l]+dis[l][j];
							dis[j][i]=dis[i][j];
						}
					}
						
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}
