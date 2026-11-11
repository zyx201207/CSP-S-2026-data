#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10,inf=1e9;
vector<int> g[N];
int n,k,fa[N],dis[N];
bool vis[N];
int find(int x){
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=y;
}
void dfs(int u,int f){
	for(int v:g[u]){
		if(v==f||vis[v]) continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfs(v,u);
	}
}
void solve_1(){
	int res=n;
	for(int i=0;i<(1<<n);i++){
		int x=i,cnt=0;
		while(x>0) cnt+=(x&1),x>>=1;
		if(cnt!=k) continue;
		for(int j=1;j<=n;j++) fa[j]=j,vis[j]=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) vis[j]=1;
		}
		for(int j=1;j<=n;j++){
			if(vis[j]){
				for(int x:g[j]){
					if(vis[x]) merge(j,x);
				}
			}
		}
		cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]&&fa[j]==j) cnt++;
		}
		if(cnt>2) continue;
		for(int j=1;j<=n;j++) dis[j]=inf;
		for(int j=1;j<=n;j++) if(vis[j]) dis[j]=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) dfs(j,0);
		}
		int ans=0;
		for(int j=1;j<=n;j++) ans=max(ans,dis[j]);
		res=min(res,ans);
	}
	cout<<res<<"\n";
}
void solve_2(){
	int m=n/2+2;
	if(n==k){
		cout<<"0\n";
		return;
	}
	if(k>=m){
		cout<<"1\n";
		return;
	}
	if(k==1){
		cout<<m/2<<"\n";
		return;
	}
	int l=1,r=m,res=m;
	while(l<=r){
		int mid=(l+r)>>1;
		int x=m-mid*2-k;
		if((x+1)/2<=mid) res=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<res<<"\n";
} 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		if(c<=3) solve_1();
		if(13<=c&&c<=14) solve_2();
		for(int i=1;i<=n;i++) vector<int>().swap(g[i]);
	}
	return 0;
}

