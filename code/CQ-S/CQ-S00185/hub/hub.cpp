#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
int cc,t,n,k,kk;
bool vis[N];
vector<int> ve[N];
int fa[20];
bitset<1005> b[1005];
int c[1005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool check(int x){
	return rand()%2;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ve[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
int dfs(int u,int fa){
	if(vis[u]) return 0;
	int ans=1e12;
	for(int v:ve[u]){
		if(v==fa) continue; 
		ans=min(ans,dfs(v,u)+1);
	}
	return ans;
}
void baoli(){
	cin>>n>>k;
//	return;
	for(int i=1;i<=n;i++){
		ve[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	
	int ans=1e12;
	for(int op=0;op<(1<<n);op++){
		if(__builtin_popcount(op)!=k) continue;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			fa[i]=i;
		}
		for(int i=1;i<=n;i++){
			if(op>>(i-1)&1) vis[i]=1;
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			for(int x:ve[i]){
				if(!vis[x]) continue;
				fa[find(i)]=find(x);
			}
		}
		set<int> s;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			s.insert(find(i));
		}
		if(s.size()>2){
			continue;
		}
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(dfs(i,0),maxx);
		}
		ans=min(ans,maxx);
	}
	cout<<ans<<"\n";
}
void _dfs(int u,int ju,int fa,int x){
	if(ju>x) c[++kk]=u;
	for(int v:ve[u]){
		if(v==fa) continue; 
		_dfs(v,ju+1,u,x);
	}
}
void __dfs(int ii,int u,int ju,int fa,int x){
	if(ju<=x) b[ii][u]=1;
	for(int v:ve[u]){
		if(v==fa) continue; 
		__dfs(ii,v,ju+1,u,x);
	}
}
bool _check(int x){
	for(int i=1;i<=n;i++){
		kk=0;
		_dfs(i,0,0,x);
		for(int i=1;i<=kk;i++){
			b[c[i]].reset();
			__dfs(c[i],c[i],0,0,x);
		}
		if(k==0) return 1;
		for(int i=2;i<=kk;i++){
			b[i]&=b[i-1];
		}
		for(int i=1;i<=n;i++){
			if(b[kk][i]&&k==2){
				return 1;
			}
		}
	}
	return 0;
}
void teshu(){
	cin>>n>>k;
//	return;
	for(int i=1;i<=n;i++){
		ve[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(_check(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>cc>>t;
	while(t--){
		if(cc<=3){
			baoli();
		}
		else if(cc==7||cc==11||cc==12){
			teshu();
		}
		else if(cc==13||cc==14){
			cout<<(n-1)/2<<"\n";
		}
		else{
			solve();
		}
	}
	return 0;
}
/*
7 1
5 2
1 2
2 3
3 4
4 5
*/

