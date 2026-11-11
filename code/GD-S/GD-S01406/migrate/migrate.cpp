#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int a[N],cnt[3005][3005],dis[3005][3005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2&&a[i]-a[i-2]<=d)f=1;
		}
		if(f==0){
			cout<<0<<endl;
			continue;
		}
		memset(dis,0x3f3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
				dis[i][j]=1;
				cnt[i][j]++;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+1;k<=j-1;k++){
					if(dis[i][k]==0x3f3f||dis[k][j]==0x3f3f)continue;
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=1;
					}else if(dis[i][k]+dis[k][j]==dis[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
				cnt[i][j]=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
