#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,ans,a[N],fa[N],fat[N],son[N],b[N],cnt[N];
vector<int> g[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
} 
void dfss(int u,int p,int sum){
	cnt[u]=min(cnt[u],sum);
	fat[u]=p;
	son[p]=u;
	for(auto v:g[u]){
		if(v!=p) dfss(v,u,sum+1);
	}
}
void f(){
	int sz=0;
	for(int i=1;i<=n;i++){
		cnt[i]=2e9;
		if(a[i]) fa[i]=i,b[++sz]=i;
		else fa[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(a[fat[i]] && a[i]) fa[find(i)]=find(fat[i]);
		if(a[son[i]] && a[i]) fa[find(i)]=find(son[i]);
	}
	int sl=0;
	for(int i=1;i<=n;i++) if(find(i)==i) sl++;
	if(sl>2) return;
	for(int i=1;i<=sz;i++) dfss(i,0,0); 
}
void dfs(int step,int cnt){
	if(step==n+1){
		f();
	}
	dfs(step+1,cnt);
	if(cnt<k){
		a[step]=1;
		dfs(step+1,cnt+1);
	}
	a[step]=0;
}


int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(13<=c && c<=14){
			int a=(n-k)/3,b=(n-k)%3;
		    cout<<a+b+1<<"\n"; 
		}else{
		    dfss(1,0,0);
			ans=2e9;
			dfs(1,0);
			cout<<ans;
		}
	} 
	return 0;
}

