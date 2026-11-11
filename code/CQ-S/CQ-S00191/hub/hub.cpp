#include<bits/stdc++.h>
using namespace std;
const int N=30+10;
int c,t,n,k,vis[N],f[N],dep[N],up[N],ans=1e9;
vector<int>tree[N]; 
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void get(int u,int fa){
	dep[u]=dep[fa]+1;
	up[u]=fa;
	for(int v:tree[u]){
		if(v==fa) continue;
		get(v,u);
	}
}
void dfs(int u,int cnt){
	if(cnt>k) return;
	if(cnt+(n-u+1)<k) return;
	if(cnt==k){
		for(int i=1;i<=n;i++){
			if(vis[i]) f[i]=i; 
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int v:tree[u]){
					if(vis[v]){
						int fi=find(i),fv=find(v);
						f[fi]=fv;
					}
				}
			}
		}
		int cnt=0;
		vector<int>v;
		for(int i=1;i<=n;i++){
			if(f[i]==i){
				bool flag=1;
				for(int j:v){
					if(i==j){
						flag=0;	
						break;
					}
				}
				if(flag){
					v.push_back(f[i]);
					cnt++;
				}
			}
		}
		if(cnt>2) return;
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(vis[i]&&vis[j]) continue;
				int x=i,y=j;
				if(dep[x]<dep[y]) swap(x,y);
				int tot=0;
				while(dep[x]>dep[y]){
					tot++;
					x=up[x];
				}
				while(dep[x]!=dep[y]){
					x=up[x],y=up[y];
					tot+=2;
				}
				res=max(res,tot);
			}
		}
		cout<<res<<'\n';
		ans=min(ans,res);
		return;
	}
	if(u>n) return;
	vis[u]=1;
	dfs(u+1,cnt+1);
	vis[u]=0;
	dfs(u+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			tree[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		ans=1e9;
		get(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
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
