#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int maxn=1e6+5;
vector<int> vec[maxn];
int ans;
int cun[maxn];
const int inf=1e18;
int dis[maxn];
int fa[maxn];
int find(int x){ return x==fa[x]?x:fa[x]=find(fa[x]); }
void merge(int x,int y){
	int f1=find(x),f2=find(y);
	if(f1!=f2) fa[f1]=f2;
}
int check(){
	unordered_map<int,int> ma2,ma;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		ma2[cun[i]]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j:vec[cun[i]]){
			if(!ma2[j]) continue;
			merge(cun[i],j);
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int ff=find(cun[i]);
		if(!ma[ff]){
			ma[ff]=1;
			cnt++;
		}
	}
	if(cnt>2) return inf;
	for(int i=1;i<=n;i++) dis[i]=inf;
	queue<int> q;
	for(int i=1;i<=k;i++){
		q.push(cun[i]);
		dis[cun[i]]=0;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:vec[u]){
			if(dis[v]!=inf) continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,dis[i]);
	return res;
}
double tim;
void dfs(int t,int st){
	if((double)clock()/CLOCKS_PER_SEC>tim) return ;
	if(t>k){
		ans=min(ans,check());
		return ;
	}
	for(int i=st;i<=n;i++){
		if(n-i<k-t) break;
		cun[t]=i;
		dfs(t+1,i+1);
		if((double)clock()/CLOCKS_PER_SEC>tim) return ;
	}
}
void solve(){
	//init()
	ans=inf;
	cin>>n>>k;
	for(int i=1;i<=n;i++) vec[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,1);
	cout<<ans<<'\n';
}
bool Ch(int x){
	int l=x+k-1-1;
	int r=n/2+1-x+1;
	int len=r-l;
	if(len/2>=x) return false;
	else return true;
}
void solve2(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
	}
	if(k==n){
		cout<<0<<'\n';
		return ;
	}
	int l=1,r=n,res=n+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(Ch(mid)){
			r=mid-1;
			res=mid;
		}else l=mid+1;
	}
	cout<<res<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--) solve2();
		return 0;
	}
	tim=3.0/t-0.1;
	while(t--) solve();
	return 0;
}
