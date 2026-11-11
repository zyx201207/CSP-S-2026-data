#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define int long long
using namespace std;

int c,t,n,d,x[100005],dis[10005][10005];
int num[10005][10005];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dis[i][i]=0;
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					dis[i][j]=dis[j][i]=x[i]-x[j];
				}
			}
		}
		
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j]+abs(x[j]-x[i])<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j]+abs(x[j]-x[i]);
						num[i][j]=1;
					}else if(dis[i][k]+dis[k][j]+abs(x[j]-x[i])==dis[i][j]){
						num[i][j]++;
					}
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && num[i][j]==2 && dis[i][j]<=2e18){
					ans++;
				}
				//cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<num[i][j]<<endl;
			}
		}
		cout<<ans/2<<endl;
	}
	return 0;
}












