#include<iostream>
#include<cmath>
#define int long long
using namespace std;
const int MAXN=310;
int x[MAXN];
int dis[MAXN][MAXN][2];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					dis[i][j][0]=0,dis[i][j][1]=0;
				}else if(abs(x[i]-x[j])<=d){
					dis[i][j][0]=1,dis[i][j][1]=1;
				}else{
					dis[i][j][0]=1E18;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k][0]+dis[k][j][0]<dis[i][j][0]){
						dis[i][j][0]=dis[i][k][0]+dis[k][j][0],dis[i][j][1]=dis[i][k][1]*dis[k][j][1];
					}else if(dis[i][k][0]+dis[k][j][0]==dis[i][j][0]){
						dis[i][j][1]+=dis[i][k][1]*dis[k][j][1];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=dis[i][j][1]==2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
