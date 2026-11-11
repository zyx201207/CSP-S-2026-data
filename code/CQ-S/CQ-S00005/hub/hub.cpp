#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans=1e9,dis[2001],g[2001][2001];
vector<int>a,p[2001];
void dfs2(int u,int fa){
	dis[u]=min(dis[u],dis[fa]+1);
	for(int v:p[u]){
		if(v!=fa) dfs2(v,u);
	}
	return;
}
void dfs(int now,int sum,int t,vector<int>p){
	if(sum==t){
		int sum=1,maxn=0;
		for(int i=0;i<p.size();i++){
			for(int j=0;j<i;j++){
				if(g[p[i]][p[j]]!=1) sum++;
			} 
		}
		if(sum>2) return;
		sort(p.begin(),p.end());
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<p.size();i++){
			dis[p[i]]=0;
			dfs2(p[i],0);
		}
		for(int i=1;i<=n;i++){
			if(!binary_search(p.begin(),p.end(),i)) maxn=max(maxn,dis[i]);
		}
		ans=min(ans,maxn);
		return;
	}
	for(int i=now;i<=n;i++){
		vector<int>p1=p;
		p1.push_back(i);
		dfs(i+1,sum+1,t,p1); 
	}
	return;
} 
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		memset(g,0,sizeof(g));
		memset(p,0,sizeof(p));
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u][v]=g[v][u]=1;
			p[u].push_back(v);
			p[v].push_back(u); 
		}
		dfs(1,0,k,a);
		cout<<ans<<"\n";
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
