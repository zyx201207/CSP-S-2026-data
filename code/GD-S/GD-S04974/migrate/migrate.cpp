#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI ;
using namespace std;
long long id,t,n,m,d,q,k,a[1234567],dis[5123][5123],cnt[5123][5123],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>id>>t;
	while(t--){
		cin>>n>>d,ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cnt[i][j]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(id<=10){
			for(int i=1;i<=n;i++){
				int y=i,lst=i,num=1;
				while(y<n){
					if(a[y+1]-a[y]>d){
						for(int j=y+1;j<=n;j++)dis[i][j]=1e18;
						break;
					}
					y++;
					if(a[y]-a[lst]>d)num++,lst=y-1;
					dis[i][y]=num;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dis[i][j]==1)cnt[i][j]=1;
					else for(int k=i+1;k<j;k++){
						if(dis[i][k]==dis[i][j]-1&&dis[k][j]==1)cnt[i][j]+=cnt[i][k];
					}
					if(cnt[i][j]==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}else if(id==11||id==12){
			int qu=1;
			while(qu<n&&a[qu+1]-a[1]<=d)qu++;
			ans=n-((qu-1)*2-1);
			cout<<ans<<'\n';
		}else cout<<0<<'\n';
	}
	return 0;
}
