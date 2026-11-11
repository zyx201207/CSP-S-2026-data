#include<bits/stdc++.h>
using namespace std;
long long dis[5005][5005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e18;
			}
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			dis[x][y]=1;
			dis[y][x]=1;
		}
		
		for(int k=1;k<n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		long long ans=1e18;
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				ans=min(ans,dis[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
