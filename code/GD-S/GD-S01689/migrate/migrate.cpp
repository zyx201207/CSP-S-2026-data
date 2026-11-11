#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
	int v,w;
};
int c,t,n,d,a[2000005];
vector<Node>g[2000005];
int dis[5005][5005],sum[2000005];
bool f[5005][5005];
bool f1[5005][5005];
void dfs(int o,int x,int pos){
	dis[o][x]=min(dis[o][x],pos);
	f[x][0]=true;
	for(auto y:g[x]){
		if(!f[y.v][0]){
			dfs(o,y.v,pos+y.w);
		}
	}
}
void dfs1(int o,int x,int pos){
	if(pos==dis[o][x]){
		sum[x]++;
	}
	for(auto y:g[x]){
		if(!f[x][y.v]){
			f[x][y.v]=true;
			dfs(o,y.v,pos+y.w);
		}
	}
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
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&abs(a[i]-a[j])<=d){
					g[i].push_back({j,abs(a[i]-a[j])});
					g[j].push_back({i,abs(a[i]-a[j])});
				}
			}
		}
		int ans=0;
		memset(dis,0x3f3f3f3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			memset(f,false,sizeof(f));
			dis[i][i]=0;
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			memset(sum,0,sizeof(sum));
			memset(f,false,sizeof(f));
			dfs1(i,i,0);
			for(int i=1;i<=n;i++){
				cout<<sum[i]<<endl;
				if(sum[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
