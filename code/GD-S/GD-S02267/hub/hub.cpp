#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
int k[510];
long long ans;
bool vis[500010]; 
vector<long long> a[510];
vector<long long> t[510];
void dfs(int now,int way,long long dis,int en){
	if(now==en){
		ans=min(ans,dis);
		return;
	}
	if(dis>=ans)return;
	for(int i=1;i<=n;i++){
		if(i==way)continue;
		for(int j=0;j<k[i];j++){
			if(a[i][j]==a[way][now]&&vis[a[i][j]]==0){
				vis[a[i][j]]=1;
				dfs(j,i,dis+t[way][a[way][now]]+t[i][j],en);
				vis[a[i][j]]=0;
				break;
			}
		}
	}
	for(int i=now+1;i<k[way];i++){
		if(vis[a[way][i]]==0){
			vis[a[way][i]]=1;
			dfs(i,way,dis,en);
			vis[a[way][i]]=0;
		}
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=10000000000000000;
		for(int i=1;i<=n;i++){
			for(int j=0;j<k[i];j++){
				if(a[i][j]==x){
					memset(vis,0,sizeof(vis));
					vis[x]=1;
					dfs(x,i,w[x]+w[y],y);
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}//O(qn^3m^4)
	return 0;
}
