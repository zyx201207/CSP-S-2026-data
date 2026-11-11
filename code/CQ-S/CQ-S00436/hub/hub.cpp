#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
vector<int> g[1000010];
int deep[1000010];
int siz=0,sum=1;
void dfs(int u,int dep,int prt){
	siz=max(siz,dep);
	for(int v:g[u]){
		if(v==prt) continue;
		dfs(v,dep+1,u);
	}
}
void dfs2(int u,int prt,int x,int l){
	if(l==-2*x){
		sum++;
		l=x;
	}
	for(int v:g[u]){
		if(v==prt) continue;
		dfs2(v,u,x,l-1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		sum=1;
		dfs(1,0,-1);
		int l=1,r=siz;
		int ans=siz;
		while(l<=r){
			int mid=l+(r-l)/2;
			dfs2(1,-1,mid,mid);
			if(sum<=d){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
