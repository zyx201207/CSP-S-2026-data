#include<iostream>
using namespace std;
int dis[305][305],n;
long long a[305],d;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dis[j][i]=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<i;j++) if(a[i]-a[j]<=d) dis[i][j]=1;
	}
	for(int i=2;i<n;i++) for(int j=1;j<i;j++) for(int k=i+1;k<=n;k++) dis[k][j]=min(dis[k][j],dis[i][j]+dis[k][i]);
	int ans=0;
	for(int i=1;i<=n;i++) for(int j=i+3;j<=n;j++){
		if(dis[j][i]==1) continue;
		int cnt=0;
		for(int k=i+1;k<j;k++) if(dis[k][i]+dis[j][k]==dis[j][i]){//判断是否为最短路 
			cnt++;
			if(cnt>2) break;
		}
		if(cnt==2) ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
