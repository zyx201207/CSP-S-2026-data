#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt[701][701];
int dis[701][701];
int x[1000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >>c>>t;
	while(t--){
		int n,d;
		cin >>n>>d;
		for(int i=1;i<=n;i++){
			cin >>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=dis[i][j]=0x3f3f3f3f;
				cnt[i][j]=cnt[j][i]=0;
			}
			dis[i][i]=0;
			cnt[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(x[i]-x[j]<=d){
					dis[i][j]=dis[j][i]=1;
					cnt[i][j]=cnt[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][i];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
						cnt[i][j]=min(cnt[i][j],3ll);
					}else{
						if(dis[i][j]==dis[i][k]+dis[k][j]){
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
							cnt[i][j]=min(cnt[i][j],3ll);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout <<ans<<'\n';
	}
	return 0;
}
