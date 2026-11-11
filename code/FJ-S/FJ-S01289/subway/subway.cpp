#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int v[N],fa[N];
int st,en,c,n,m,d,q;
vector<int>son[N];
bool visit[N];
bool flag;
struct T{
	int x,y,w;
}a[N];
bool cmp(T a,T b){
	return a.w<b.w;
}
int fin(int x){
	if(fa[x]=x) return x;
	else return fa[x]=fin(fa[x]);
}
void dfs(int x,int w){
	visit[x]=1;
	if(x==en){
		flag=1;
		cout<<w<<'\n';
		return;
	}
	for(auto i:son[x]){
		int k=a[i].x;
		if(k==x) k=a[i].y;
		if(!visit[k]) dfs(k,a[i].w+w);
		if(flag) return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>v[i];
	int k,u,w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			a[++cnt].x=i+m;
			a[cnt].y=u;
			a[cnt].w=w;
		}
	}
	for(int i=1;i<=n+m;i++)
		fa[i]=i;
	sort(a+1,a+1+cnt,cmp);
	k=0;
	for(int i=1;i<=cnt;i++){
		int x=a[i].x,y=a[i].y;
		int xx=fin(x),yy=fin(y);
		if(xx!=yy){
			fa[yy]=xx;
			k++;
			son[x].push_back(i);
			son[y].push_back(i);
		}
		if(k==m+n-1) break;
	}
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		flag=0;
		memset(visit,0,sizeof visit);
		dfs(st,v[st]+v[en]);
	}
	return 0;
}