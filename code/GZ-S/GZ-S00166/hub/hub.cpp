//GZ-S00166 甘梓辰 贵阳市第一中学
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int c,t,n,k,u[1000005],v[1000005],d[1000005],dep[1000005],dp[1000005],fa[1000005],cnt[1000005],f[1000005][2];
vector<int> e[1000005];
vector<pii> p[1000005];
struct node{
	int u,v,dis;
};
bool cmp(pii a,pii b){
	if(a.first==b.first){
		return fa[a.second]<fa[b.second];
	}
	return a.first>b.first;
}
void dfs(int u,int fa){
	f[u][0]=f[u][1]=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u);
		f[u][0]=max(f[u][0],f[v][0]);
		f[u][0]=max(f[u][0],f[v][1]+f[u][1]+1);
		f[u][1]=max(f[u][1],f[v][1]+1);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		dp[i]=0;
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
		dp[u[i]]++;
		dp[v[i]]++;
	}
	if(k==n){
		cout<<0<<'\n';
		return ;
	}
	if(n==2){
		cout<<1<<'\n';
		return ;
	}
	if(k==1){
		dfs(1,0);
		cout<<(f[1][0]+1)/2<<endl;
		return ;
	}
	int ans=n;
	for(int i=1;i<n;i++){
		int pu=min(u[i],v[i]),pv=max(u[i],v[i]);
		for(int j=1;j<=n;j++){
			d[j]=dp[j];
			cnt[j]=0;
			dep[j]=n;
		}
		d[u[i]]--;
		d[v[i]]--;
		queue<int> q;
		for(int j=1;j<=n;j++){
			if(d[j]==1){
				q.push(j);
				dep[j]=1;
			}
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			d[u]=0;
			int flag=0;
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i];
				if(min(u,v)==pu&&max(u,v)==pv) continue;
				if(d[v]){
					flag=1;
					d[v]--;
					if(d[v]==1){
						dep[v]=min(dep[v],dep[u]+1);
						q.push(v);
					}
				}
			}
			if(!flag){
				dep[u]=n;
			}
		}
//		int dpd=0;
//		for(int i=1;i<=n;i++){
//			if(dep[i]==n){
//				dpd++;
//			} 
//		}
//		cout<<dpd<<endl;
		for(int i=1;i<=n;i++){
			cnt[dep[i]]++;
		}
		for(int i=1;i<=n/2;i++){
			cnt[i]+=cnt[i-1]; 
			if(n-cnt[i]<=k){
				ans=min(ans,i);
				break;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
    	solve();
	}
	return 0;
}

