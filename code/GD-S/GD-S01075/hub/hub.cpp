#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,t,n,k,cnt,ans,d[N],dis[N];
bool vis[N];
vector<int> vec[N];
int popcount(int x){
	int res=0;
	while(x){
		res+=x&1;
		x>>=1;
	}
	return res;
}
void dfs1(int u,int f,int mask){
	vis[u]=true;
	for(int v:vec[u]){
		if(v==f||!(mask&(1<<(v-1)))) continue;
		dfs1(v,u,mask);
	}
}
void dfs2(int u,int f){
	dis[u]=dis[f]+1;
	for(int v:vec[u]){
		if(v==f) continue;
		dfs2(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) vec[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if(n<=10){
		ans=0x3f3f3f3f;
		for(int mask=(1<<k)-1;mask<(1<<n);mask++){
			if(popcount(mask)!=k) continue;
			cnt=0;
			memset(vis,false,sizeof(vis));
			for(int i=1;i<=n;i++){
				if(!vis[i]&&mask&(1<<(i-1))){
					if(cnt==2){
						cnt++;
						break;
					}
					dfs1(i,0,mask);
					cnt++;
				}
			}
			if(cnt>2) continue;
			memset(d,0x3f,sizeof(d));
			int maxn=0;
			dis[0]=-1;
			for(int i=1;i<=n;i++){
				dfs2(i,0);
				for(int j=1;j<=n;j++){
					if(!(mask&(1<<(j-1)))) continue;
					d[i]=min(d[i],dis[j]);
				}
				maxn=max(maxn,d[i]);
			}
			ans=min(ans,maxn);
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
