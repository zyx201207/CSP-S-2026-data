#include<bits/stdc++.h>
using namespace std;
#define int long long
//c,想到整洁蛋美食剑了 
int c,t,n,d,a[100005],dis[505][505],zd[505][505],ans;
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(dis[i][j]>dis[i][k]+dis[j][k]){
					dis[i][j]=dis[i][k]+dis[j][k];
					zd[i][j]=1;
				}else if(dis[i][j]==dis[i][k]+dis[j][k])zd[i][j]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			cin>>n>>d;
			ans=0;
			memset(dis,0x3f,sizeof(dis));
			memset(zd,0,sizeof(zd));
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				dis[i][i]=0;
				for(int j=i+1;j<=n;j++){
					if(i==j)continue;
					if((int)abs(a[j]-a[i])<=d){
						dis[i][j]=1;
						zd[i][j]=1;
					}
				}
			}
			Floyd();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(zd[i][j]==2&&dis[i][j]>=2){
						ans++;
//						cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<zd[i][j]<<endl;
					}
				}
			}
			cout<<ans<<endl;
		}
	}else{
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n-3;i++){
				if(a[i+1]-a[i]<=d&&a[i+2]-a[i+1]<=d&&a[i+3]-a[i+2]<=d){
					if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
						ans++;
//						cout<<i<<' '<<i+3<<endl;
					}
				}
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
//差一步美满
