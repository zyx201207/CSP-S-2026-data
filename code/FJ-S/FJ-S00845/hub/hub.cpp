#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
using namespace std;
const int N=1e6+5;
int n,k,Ans=1e18,Res=1e18;
int f[N];
vector<pr>e;
vector<int>mp[N];
bool vis[N],bit[N];
int Find(int x){
	if(f[x]==x) return x;
	return f[x]=Find(f[x]);
}
void merge(int u,int v){
	int r1=Find(u);
	int r2=Find(v);
	if(r1==r2) return;
	f[r2]=r1;
}
bool DFS2(int fa,int x,int y,int step){
	if(x==y){
//		if(step<=0) cout<<fa<<" "<<x<<" "<<y<<"\n";
		Res=min(Res,step);
		return true;
	}
//	cout<<x<<" "<<fa<<"\n";
	for(int u:mp[x])
		if(u!=fa){
			bool flag=DFS2(x,u,y,step+1);
			if(flag) return true;
		}
	return false;
}
void DFS(int x,int cnt){
	if(x>=n-1||cnt>=k){
		for(int i=1;i<=n;i++)
			f[i]=i;
		memset(bit,0,sizeof(bit));
		for(int i=0;i<n-1;i++)
			if(vis[i]){
				merge(e[i].first,e[i].second);
				bit[e[i].first]=bit[e[i].second]=true;
			}
		set<int>root;
		for(int i=1;i<=n;i++)
		  if(bit[i]) root.insert(Find(i));
		if(root.size()>2) return;
//		cout<<"bitbmtt";
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(bit[i]&&bit[j]&&i!=j){
					Res=1e18;
					DFS2(0,i,j,0);
					ans=max(ans,Res);
//					cout<<Res<<" ";
//					if(Res<=0) cout<<i<<" "<<j<<"\n";
				}
//		cout<<cnt<<" "<<ans<<"\n";
		Ans=min(Ans,ans);
//		cout<<cnt<<" ";
		return;
	}
	vis[x]=true;
	DFS(x+1,cnt+1);
	vis[x]=false;
	DFS(x+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		e.clear();
		for(int i=1;i<=n;i++)
		   mp[i].clear();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e.push_back({u,v});
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		DFS(0,0);
		cout<<Ans<<"\n";
	}
	return 0;
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
