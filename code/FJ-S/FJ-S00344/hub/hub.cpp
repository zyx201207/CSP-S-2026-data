#include<bits/stdc++.h>
using namespace std;
int n,m,T,b[1000005],fa[1000005],ans,dis[5005][5005];
pair<int,int> p[1000005];
vector<int> v[1000005];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y)fa[y]=x;
}
void dfsdfs(int x,int f,int rt){
	dis[rt][x]=dis[rt][f]+1;
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]!=f)dfsdfs(v[x][i],x,rt);
	}
}
void dfs(int x,int res){
	if(res>m)return ;
	if(x>n){
		if(res<m)return ;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<n;i++){
			if(b[p[i].first]&&b[p[i].second])merge(p[i].first,p[i].second);
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(b[i]&&i==find(i))res++;
		}
		if(res<=2){
			int res=0;
			for(int i=1;i<=n;i++){
				int f=1145141919;
				for(int j=1;j<=n;j++){
					if(b[j])f=min(f,dis[i][j]-1);
				}
				res=max(f,res);
			}
			ans=min(ans,res);
		}
		return ;
	}
	b[x]=1;
	dfs(x+1,res+1);
	b[x]=0;
	dfs(x+1,res);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>T;
	while(T--){
		cin>>n>>m;
		ans=1145141919;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
			p[i].first=x;
			p[i].second=y;
		}
		for(int i=1;i<=n;i++)dfsdfs(i,0,i);
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
