#include<bits/stdc++.h>
using namespace std;
int dis[1005][1005];
int n,m,t,c,a[100005],ans;
int floyd(){
	for(int i=1;i<=n;i++){
		dis[i][i]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
				else if(dis[i][k]+dis[k][j]==dis[i][j]){
					ans++;
				}
				if(i==1&&j==4&&k==3){
					cout<<dis[1][4]<<" "<<dis[1][3]+dis[3][4]<<endl;
				}
				if(i==1&&j==4&&k==3)
				{
					cout<<dis[1][4]<<" "<<dis[1][2]+dis[2][4]<<endl;
				}
			} 
		}
	}
	return 0;
	
}
int main(){
	cin>>c>>t;
	while(t--){
		memset(dis,0x3f,sizeof(dis));
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			dis[i][i+1]=(a[i+1]-a[i]);
		}
		floyd();
		cout<<ans<<" "<<dis[1][3]<<" "<<dis[2][4]<<endl;
		memset(dis,0,sizeof(dis));
	}

	
	return 0;
}
