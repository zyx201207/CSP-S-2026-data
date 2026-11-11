#include<bits/stdc++.h>
using namespace std;
int m,n,q,d,s;
vector<vector<pair<int,int> > >b;
long long sum[501000];
int w[500010],k[500010],fa[501000],fath[501000][30],dep[501000],vis[501000];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fath[x][i]]>=dep[y]){
			x=fath[x][i];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fath[x][i]!=fath[y][i]){
			x=fath[x][i];
			y=fath[y][i];
		}
	}
	if(x==s)return x;
	return fath[x][0];
}
void dfs(int u,int fa){
	vis[u]=1;
	for(int i=0;i<b[u].size();i++){
		int v=b[u][i].first,val=b[u][i].second;
		if(v==fa)continue;
		sum[v]=sum[u]+val;
		dep[v]=dep[u]+1;
		fath[v][0]=u;
		dfs(v,u);
	}
	return ;
}

struct node{
	int u,v,val;
}a[501000];
bool cnt(node x,node y){
	return x.val<y.val;
}
int main(){
	freopen("subway.in","r",stdin);
//	freopen("subway.out","r",stdout);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	b.resize(m+n+2);
	int uu=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[++uu].u=m+i;
			a[uu].v=x;
			a[uu].val=y;
			fa[x]=x;
			fa[m+i]=m+i;
		}
	}
	sort(a+1,a+uu+1,cnt);
	int js=0;
	for(int i=1;i<=uu;i++){
		int x=a[i].u,y=a[i].v;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			b[x].push_back(make_pair(y,a[i].val));
			b[y].push_back(make_pair(x,a[i].val));
			fa[fx]=fy;
			js++;
			if(js==n+m-1)break;
		}
	}
	s=find(1);
	dep[s]=1;
	dfs(s,0);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n+m&&dep[j]>(1<<i);j++){
			fath[j][i]=fath[fath[j][i-1]][i-1];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int an=lca(x,y);
		long long ans=sum[x]+sum[y]-2*sum[an];
		//if(dep[an]>dep[x]||dep[an]>dep[y])cout<<-1;
		//if(dep[an]==0)cout<<-1;
		ans+=w[x];
		ans+=w[y];
	//	if(vis[x]==0||vis[y]==0)cout<<-1;
		cout<<ans<<"\n";
	}
	return 0;
}
