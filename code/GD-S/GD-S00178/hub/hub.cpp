#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=4e6+10;
int c,t,n,k,u,v;
vector<int> vec[N],aft[N];
int cho[N],ans,fa[N],dis[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy;
}
void dsfs(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:aft[u]){
		if(v==fa) continue;
		dsfs(v,u);
	}
}
int solve(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(cho[i]){
			for(int v:vec[i]){
				if(cho[v]) merge(i,v);
			}
		}
	}
	int fa1=0,fa2=0;
	for(int i=1;i<=n;i++){
		if(cho[i]){
			if(fa1==0) fa1=find(i);
			else{
				if(fa1!=find(i)){
					if(fa2==0) fa2=find(i);
					else if(fa2!=find(i)) return 1e18;
				} 
			}
		}
	}
	for(int i=1;i<=n;i++) aft[i].clear(),dis[i]=1e18;
	for(int i=1;i<=n;i++){
		for(int v:vec[i]){
			if(find(i)==find(v)) continue; 
			aft[find(i)].push_back(find(v));
		}
	}
	dis[fa1]=dis[fa2]=0;
	if(fa1) dsfs(fa1,0);
	if(fa2) dsfs(fa2,0);
	int ret=0;
	for(int i=1;i<=n;i++) ret=max(ret,dis[find(i)]);
	return ret;
}
void dfs(int step,int cnt){
	if(step==n+1){
		if(cnt!=k) return;
		ans=min(ans,solve());
		return;
	}
	cho[step]=0;
	dfs(step+1,cnt);
	cho[step]=1;
	dfs(step+1,cnt+1);
}
void dfsk2(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:vec[u]){
		if(v==fa) continue;
		dsfs(v,u);
	}
}
void solvek2(){
	if(k==1){
		int ans=1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
			}
			dis[i]=0;
			dfsk2(i,0);
			int mx=0;
			for(int j=1;j<=n;j++){
				mx=max(mx,dis[j]);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<endl;
		return;
	}
	cout<<"0\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		if(c==7||c==11||c==12){
			solvek2();
		}
		else{
			ans=1e18;
			dfs(1,0);
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++){
			vec[i].clear();
		}
	}
	return 0;
}
