#include<bits/stdc++.h>
using namespace std;

int c,t,n,k,dis[4005][4005],ans,p[4005][4005],m,l,r;
vector<int> V[1000005];
bool flag[4005];
struct Edge{
	int a,f,maxx;
	bool operator < (Edge _)const{
		return maxx<_.maxx;
	}
}e[1000005]; 
priority_queue<Edge> q,kong;

void dfs1(int u,int fa,int x,int s){
	dis[u][x]=dis[x][u]=s;
	for(int i=0;i<V[u].size();i++){
		int v=V[u][i];
		if(v!=fa)
			dfs1(v,u,x,s+1);
	}
	return;
}

int dfs2(int u,int fa){
	int maxxx=0;
	for(int i=0;i<V[u].size();i++){
		int v=V[u][i];
		if(v!=fa)
			maxxx=max(maxxx,dfs2(v,u)+1);
	}
	return maxxx;
}

int solve(int x){
	while(x--){
		int u=q.top().a;
		int v=q.top().f;
		int w=q.top().maxx;
		q.pop();
		for(int i=0;i<V[u].size();i++){
			int vv=V[u][i];
			if(vv!=v)
				q.push({vv,u,p[vv][u]});
		}
	}
	return q.top().maxx+1;
}

int dfs3(int u,int fa,int x){
	for(int i=0;i<V[u].size();i++){
		int v=V[u][i];
		if(v!=fa){
			int w=dfs3(v,u,x);
			if(w==1){
				flag[u]=true;
				if(v==x)
					r=u;
				if(u==fa)
					l=v;
			}
		}
	}
	if(u==x)
		flag[u]=true;
	return flag[u];
}

void dfs4(int u,int x,int y){
	flag[u]=true;
	m=max(m,min(dis[u][x],dis[u][x]));
	for(int i=0;i<V[u].size();i++){
		int v=V[u][i];
		if(!flag[v])
			dfs4(v,x,y);
	}
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n;i++)
			V[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			V[u].push_back(v);
			V[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			dfs1(i,i,i,0);
		for(int i=1;i<=n;i++){
			for(int j=0;j<V[i].size();j++)
				p[i][V[i][j]]=dfs2(i,V[i][j]);
			p[i][i]=dfs2(i,i);
		}				
		for(int i=1;i<=n;i++){
			q=kong;
			q.push({i,i,p[i][i]});
			u=solve(k);
			ans=min(ans,u);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++){
				m=0;
				memset(flag,0,sizeof(flag));
				u=dfs3(i,i,j);
				for(int l=1;l<=n;l++)
					if(flag[l] && l!=i && l!=j)
						dfs4(l,i,j);	
				q=kong;
				q.push({i,l,p[i][l]});
				q.push({j,r,p[j][r]});
				u=solve(k);
				ans=min(ans,max(u,m));
			}
		cout<<ans<<"\n";
	}
	return 0;
}
