#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
vector<int> G[N];
mt19937 rnd(time(0));
int n,k,mx,s,t,ind[N],dis[N],f[N],L[N],R[N]; 
void dfs1(int u,int pre,int dep) {
	if(dep>mx) mx=dep,t=u;
	else if(dep==mx) {if(rnd()&1) t=u;}
	for(int v:G[u]) {
		if(v==pre) continue;
		dfs1(v,u,dep+1);
	}
}
vector<int> tmp,d;
void dfs2(int u,int pre,int x) {
	tmp.push_back(u);
	if(u==x) d=tmp;
	for(int v:G[u]) {
		if(v==pre) continue;
		dfs2(v,u,x);
	}
	tmp.pop_back();
}
void dfs3(int u,int pre) {
	dis[u]=0;
	for(int v:G[u]) {
		if(v==pre||ind[v]) continue;
		dfs3(v,u);
		dis[u]=max(dis[u],dis[v]+1);
	}
}
bool check(int x) {
	int sum=0;
	for(int i=1; i<=n; i++) sum+=(dis[i]>=x);
	if(sum>k) return false;
	int l=d.size()-1,r=0;
	for(int i=0; i<d.size(); i++) {
		f[i]=x-min(dis[d[i]],x);
		l=min(l,i+f[i]),r=max(r,i-f[i]);
		sum-=(!f[i]);
	}
	if(l>=r) sum++;
	else {
		sum+=r-l+1,l++,r--;
		for(int i=l,j=l-1; i<=r; i++) {
			while(j<r&&f[j+1]>j-i+1) j++;
			R[i]=j;
		}
		for(int i=r,j=r+1; i>=l; i--) {
			while(j>l&&f[j-1]>i-j+1) j--;
			L[i]=j;
		}
		int mx=0;
		for(int i=l,j=l-1; i<=r; i++) {
			while(j<r&&R[i]+1>=L[j+1]) j++;
			mx=max(mx,j-i+1);
		}
		sum-=mx;
	}
	return sum<=k;
}
void work() {
	cin>>n>>k;
	for(int i=1; i<=n; i++) vector<int>().swap(G[i]),ind[i]=false;
	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	mx=0,dfs1(1,0,1),s=t;
	mx=0,dfs1(s,0,1);
	dfs2(s,0,t);
	for(int u:d) ind[u]=true;
	for(int u:d) dfs3(u,0);
	int l=0,r=n,ans;
	while(l<=r) {
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<"\n";
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int cid,T;
	cin>>cid>>T;
	while(T--) work();
	return 0;
}
//samples passed at 16:00
//18:07 pai chu guo le,mei xiang ming bai za gai,sui ji shu kai du,hao xiang AK bu liao le
