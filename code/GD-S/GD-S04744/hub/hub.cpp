//hub
#include<bits/stdc++.h>
#define p_b push_back
typedef long long ll;
using namespace std;
const int N=4e3+33,inf=1e7;
int sub,t,n,k,fa_[N],d[N],fa[N][21];
set<int>st,st_;
vector<int>edge[N];
int find(int x){
	if(fa_[x]==x) return x;
	return fa_[x]=find(fa_[x]);
}
void merge(int u,int v){
	u=find(u),find(v);
	if(u==v) return ;
	fa_[v]=u;
}
int count(int x){
	int res=0;
	while(x){
		res+=x%2;
		x>>=1;
	}
	return res;
}
void dfs(int u,int f){
	d[u]=d[f]+1,fa[u][0]=f;
	for(int v:edge[u]){
		if(v==f) continue;
		dfs(v,u);
	}
}
void pre(){
	for(int j=1;j<=17;j++){
		for(int i=1;i<=n;i++){
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
}
int dis(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	int del=d[u]-d[v],cnt=0;
	int res=0;
	while(del){
		if(del&1) u=fa[u][cnt],res+=(1<<cnt);
		del>>=1,cnt++;
	}
	if(u==v) return res;
	for(int j=17;j>=0;j--){
		if(fa[u][j]!=fa[v][j]){
			u=fa[u][j],v=fa[v][j];	
			res+=(1<<j),res+=(1<<j);
		}
	}
	res+=2;
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>sub>>t;
	while(t--){
		cin>>n>>k;
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=n;i++){
			fa_[i]=i;
			edge[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].p_b(v);
			edge[v].p_b(u);
		}
		dfs(1,0);
		pre();
		int ans=n;
		for(int mask=1;mask<(1<<n);mask++){
			if(count(mask)!=k) continue;
			st.clear();
			st_.clear();
			for(int i=1;i<=n;i++) fa_[i]=i;
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))){
					for(int j:st){
						if(fa[i][0]==j||fa[j][0]==i) merge(i,j);
					}
					st.emplace(i);
				}
			}
			for(int i:st) st_.emplace(find(i));
			if(st_.size()<=2){
				int nw=0;
				for(int i=1;i<=n;i++){
					if(st.find(i)!=st.end()) continue;
					int d=n;
					for(int j:st){
						d=min(d,dis(i,j));
					}
					nw=max(nw,d);
				}
				ans=min(ans,nw);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
Sub 1~3 ver.(bit)

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
