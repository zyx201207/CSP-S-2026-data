#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
long long dis[9005][9005],ans;
int f[9005][9005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=1e18;
				if(a[j]-a[i]<=d){
					dis[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(dis[i][j]+dis[j][k]<dis[i][k]){
						dis[i][k]=dis[i][j]+dis[j][k];
						f[i][k]=1;
					}else if(dis[i][j]+dis[j][k]==dis[i][k]){
						f[i][k]++;
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
/*			for(int j=1;j<=i;j++){
				cout<<0<<" ";
			}*/
			for(int j=i+1;j<=n;j++){
//				cout<<f[i][j]<<" ";
				if(f[i][j]==2){
					ans++;
				}
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
