#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],dist[2000005],vis[2000005];
void dfs(int id,int cnt){
	if(id<1 || id>n) return ;
	if(cnt>2) return ;
	if(dist[id]>cnt){
		dist[id]=cnt;
		vis[id]=1;
	}
	else if(dist[id]==cnt) vis[id]++;
	int len=0;
	for(int i=id+1;i<=n;i++){
		len=a[i]-a[id];
		if(len>d) break;
		dfs(i,cnt+1);
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[j]=INT_MAX;
				vis[j]=-1;
			}
			dist[i]=-1;
			vis[i]=0;
			dfs(i,0);
			for(int j=i;j<=n;j++){
				//cout<<dist[j]<<' '<<vis[j]<<" | ";
				if(dist[j]==2 && vis[j]==2) ans++;
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
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
