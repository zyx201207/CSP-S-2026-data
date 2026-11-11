#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e6+5;
vector<int>a[maxn];
struct node{
	int data,dep;
}st[maxn][21];
vector<node>dfn(1);
int fa[maxn],dep[maxn],pos[maxn];
unordered_set<int>s;
bool vis[maxn];
int n,k;
void dfs(int x){
	pos[x]=dfn.size();
	dfn.push_back({x,dep[x]});
	for(auto i:a[x]){
		if(i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
			dfn.push_back({x,dep[x]});
		}
	}
}
int lca(int x,int y){
	int l=pos[x],r=pos[y];
	if(l>r)swap(l,r);
	int len=log2(r-l+1);
	if(st[l][len].dep<st[r-(1<<len)+1][len].dep)return st[l][len].data;
	else return st[r-(1<<len)+1][len].data;
}
int dis(int x,int y){
	int tmp=lca(x,y);
	return dep[x]+dep[y]-2*dep[tmp];
}
int pop_count(int x){
	int res=0;
	for(int i=0;i<10;i++){
		if(((1<<i)&x)!=0)res++;
	}
	return res;
}
void dfss(int x){
	vis[x]=1;
	for(auto i:a[x]){
		if(vis[i] or s.find(i)==s.end())continue;
		dfss(i);
	}
}
bool chk(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i] or s.find(i)==s.end())continue;
		dfss(i);
		cnt++;
		if(cnt>2)return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1);
		int N=dfn.size()-1;
		for(int i=1;i<=N;i++)st[i][0]=dfn[i];
		for(int j=1;j<=log2(N)+1;j++){
			for(int i=1;i+(1<<j)-1<=N;i++){
				if(st[i][j-1].dep<st[i+(1<<(j-1))][j-1].dep)st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1<<(j-1))][j-1];
			}
		}
		int ans=0x3f3f3f3f;
		for(int msk=0;msk<pow(2,n);msk++){
			if(pop_count(msk)!=k)continue;
			s.clear();
			for(int i=0;i<10;i++){
				if(((1<<i)&msk)!=0){
					s.insert(i+1);
					vis[i+1]=0;
				}
			}
			if(!chk())continue;
			int res=0;
			for(int i=1;i<=n;i++){
				int ress=0x3f3f3f3f;
				for(auto j:s)ress=min(ress,dis(i,j));
				res=max(ress,res);
			}
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
		dfn.clear();
		for(int i=1;i<=n;i++){
			fa[i]=pos[i]=dep[i]=0;
			a[i].clear();
		}
		dfn.push_back({0,0});
	}
	return 0;
}
