#include<bits/stdc++.h>
#define ll long long
#define N 4010
using namespace std;
ll n,m,T,ans;
ll a[N],d[N];
bool vis[N];
vector<ll>v[N];
queue<ll>q;
void dfs(ll x){
	ll i,y;
	vis[x]=1;
	for(i=0;i<v[x].size();i++){
		y=v[x][i];
		if(a[y]==0)continue;
		if(vis[y])continue;
		dfs(y);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll i,j,k,x,y;
	cin>>T>>T;
	while(T--){
		cin>>n>>m;
		ans=n;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(i=0;i<(1<<n)-1;i++){
			x=0;
			for(j=1;j<=n;j++){
				if(i&(1<<(j-1)))a[j]=1,x++;
				else a[j]=0;
				if(x>m)break;
			}
			if(x!=m)continue;
			memset(vis,0,sizeof(vis));
			memset(d,0,sizeof(d));
			x=0;
			for(j=1;j<=n;j++)if(a[j]&&vis[j]==0)dfs(j),x++;
			if(x>2)continue;
			for(j=1;j<=n;j++)if(vis[j])q.push(j);
			ll tem=0;
			while(!q.empty()){
				x=q.front(),q.pop();
				for(j=0;j<v[x].size();j++){
					y=v[x][j];
					if(vis[y])continue;
					vis[y]=1;
					d[y]=d[x]+1;
					tem=max(d[y],tem);
					q.push(y);
				}
			}
//			for(i=1;i<=n;i++)cout<<d[i]<<"\n";
			ans=min(ans,tem);
		}
		cout<<ans<<"\n";
	}
}
