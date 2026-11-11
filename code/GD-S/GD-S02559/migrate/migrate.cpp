#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,w;
};
typedef pair<int,int> pii;
const int N=2e6+7;
int n,d,a[N],t,c,dis[N],ans;
bool vis[N],vis2[N];
vector<node> g[N];
void Dij(int s)
{
	
	memset(vis,false,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,s});dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(node i:g[u]){
			if(a[u]<a[i.v]){
				if(dis[i.v]>dis[u]+i.w){
					cout<<dis[i.v]<<" "<<dis[u]<<" "<<i.w;
					dis[i.v]=dis[u]+i.w;
					q.push({dis[i.v],i.v});
				}
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(a[i]-a[j])<=d)g[a[i]].push_back({a[j],abs(a[i]-a[j])});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[j]=1e18;
			Dij(i);
		//	for(int j=1;j<=n;j++)cout<<dis[j];
			for(int j=1;j<=n;j++){
				if(vis2[dis[j]])ans++;
				else vis2[dis[j]]=true;
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(vis2,false,sizeof(vis2));
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
