#include<bits/stdc++.h>
#define ll long long
#define N 5001
#define INF 4e18
using namespace std;
ll c,t,n,d,a[N],dis[N][N],cnt[N][N],r[N],ans,now,id;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) dis[i][j]=INF;
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(j==i){
				dis[i][j]=0;
				continue;
			}
			if(a[i]+d>=a[j]) dis[i][j]=cnt[i][j]=1;
			else{
				r[i]=j-1;
				break;
			}
		}
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]>dis[i][k]+dis[k][j]){
				dis[i][j]=dis[i][k]+dis[k][j];
				cnt[i][j]=cnt[i][k]*cnt[k][j];
			}else if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(cnt[i][j]==2) ans++;
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) cnt[i][j]=0;
	}
	return 0;
} 
