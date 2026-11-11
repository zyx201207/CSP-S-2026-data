/*



*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=0x3f3f3f3f3f3f;
int c,t,n,k,f[20],cnt,dis[20];
vector<int> e[20],root;
bool fl[20];
void clear(vector<int> &x){
	vector<int> xx;
	x=xx;
}
int get(int x){
	if(f[x]==x)
		return x;
	return f[x]=get(f[x]);
}
bool ck(){
	int tot=k;
	for(int i=1;i<=n;f[i]=i,i++);
	for(auto it:root)
		for(auto itt:e[it]){
			if(!fl[itt])
				continue;
			int fa=get(it),fb=get(itt);
			if(fa!=fb){
				f[fa]=fb;
				tot--;
			}
		}
	if(tot>2)
		return 1;
	return 0;
}
void dfs(int id,int fa,int h){
	dis[id]=min(dis[id],h);
	for(auto it:e[id])
		if(it!=fa)
			dfs(it,id,h+1);
}
int wk(int S){
	cnt=0;
	int d=0;
	for(int i=1;i<=n;dis[i]=MAX,i++);
	for(int i=1;i<=n;fl[i]=0,i++);
	clear(root);
	for(int i=1;i<=n;i++){
		fl[i]=(S>>(i-1))&1;
		cnt+=fl[i];
		if(fl[i])
			root.push_back(i);
	}
	if(cnt!=k)
		return MAX;
	if(ck())
		return MAX;
	for(auto it:root)
		dfs(it,0,0);
	for(int i=1;i<=n;d=max(d,dis[i]),fl[i]=0,i++);
	clear(root);
	return d;
}
void solve(){
	int ans=0x3f3f3f3f3f3f;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int S=3;S<(1<<n);S++)
		ans=min(ans,wk(S));
	cout<<ans<<'\n';
	for(int i=1;i<=n;clear(e[i]),i++);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}

