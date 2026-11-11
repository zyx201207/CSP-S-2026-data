#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006],dis[5005][5005],road[5005][5005],cnt;
long long f[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++){
				dis[j][i]=1e9;
				road[i][j]=1e9;
				f[i][j]=0;
				if(a[i]-a[j]<=d){
					dis[j][i]=1;
					road[j][i]=1;
				}
			}
			
		}
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			road[i][i]=0;
		}
		for(int k=1;k<=n;k++){
			    for(int i=1;i<=n;i++){
			    	for(int j=i+1;j<=n;j++){
			    		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		for(int k=1;k<=n;k++){
			    for(int i=1;i<k;i++){
			    	for(int j=k+1;j<=n;j++){
			    		long long o=road[i][k]+road[k][j];
			    		if(dis[i][j]==o&&dis[i][j]>1&&dis[i][j]<1e9){
			    			if(f[i][j]==1){
			    				cnt++;
			    				f[i][j]++;
							}else if(f[i][j]==0){
								f[i][j]++;
							}else{
								cnt--;
							}
						}
			    		road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
					}
				}
			}
		cout<<cnt<<endl;
	}
	return 0;
}
