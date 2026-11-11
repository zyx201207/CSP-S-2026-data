#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],c,t,n,d,dist[10010][10010],vis[10010][10010];
int spfa(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				int cnt=dist[i][k]+dist[k][j];
				if(cnt<dist[i][j]) dist[i][j]=cnt,vis[i][j]=1;
				else if(cnt==dist[i][j]) vis[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[i][j]==2){
				//cout<<i<<' '<<j<<' ';
				ans++;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof a);
		memset(vis,0,sizeof vis);
		memset(dist,0x3f,sizeof dist);
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=abs(a[i]-a[j]);
				if(d>=t){
					dist[i][j]=1;
				}
			}
		}
		cout<<spfa()<<endl;
	}
	return 0;
}
