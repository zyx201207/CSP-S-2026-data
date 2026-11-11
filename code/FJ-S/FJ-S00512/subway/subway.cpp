#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500010],head[5000010],cnt=0,dis[2500010],num[500010],ed[100010],ans[100010];
struct sl{
	int l,r;
}E[500010];
vector<int>t[510],st[500010];
bool vis[2500010],bj[500010];
struct node{
	int to,next,w;
}e[5000010];
bool cmp(sl a,sl b){
	return a.l<b.l;
}
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].w=w;
	head[u]=cnt;
}
void dij(int s){
	priority_queue<pair<int,int> >z;
	z.push(make_pair(0,s));

//	memset(dis,0x3f,sizeof(dis));
//	memset(vis,0x3f,sizeof(vis));
	for(int i=0;i<=(m+1)*d;i++)vis[i]=0,dis[i]=1e9;
	dis[s]=0;
	while(z.size()){
		int x=z.top().second;
		z.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int v=e[i].to;
			if(dis[x]+e[i].w<dis[v]){
				dis[v]=dis[x]+e[i].w;
				z.push(make_pair(-dis[v],v));
			}
		}
	}
	
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
memset(ans,0x3f,sizeof(ans));
scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
for(int i=1;i<=m;i++){
	scanf("%d",&w[i]);
}
for(int i=1;i<=n;i++){
	int k,lx;
	scanf("%d",&k);
	for(int j=1;j<=k;j++){
		
		scanf("%d%d",&E[j].l,&E[j].r);
	}
	sort(E+1,E+1+k,cmp);
		//v[x].push_back(y);
		for(int j=1;j<=k;j++){
		int x,y;
		x=E[j].l;
		y=E[j].r;
		num[x]+=m;
		add(x,x+num[x],y);//层与层建边 
		add(x+num[x],x,y); 
		//cout<<x<<" "<<x+num[x]<<endl;
		if(j>=2)add(lx+num[lx],x+num[x],0),add(x+num[x],lx+num[lx],0);//每层间建边 
		
		lx=x;
	}
	//cout<<endl;
}
for(int i=1;i<=q;i++){
	int xr,yr;
	scanf("%d%d",&xr,&yr);
	st[xr].push_back(i);
	ed[i]=yr;
}
for(int i=1;i<=m;i++){
	if(!st[i].size())continue;
	dij(i); 
	for(int j=0;j<st[i].size();j++){
		int l=st[i][j],p;
		p=ed[l];
	    ans[l]=dis[p]+w[p]+w[i];
	}
}
for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
return 0;
}
/*
考虑对每个点跑dij
那么，一共有md个点，需要多源最短路……从q入手，离线处理一下，只需要算至少q/2个点的最短路 O(q/2*(md)log(md))
*/
/*
0 3 5 3 1
1 1 1 1 1
2 1 3 3 7  
2 2 10 4 11
3 1 8 2 15 5 20
1 5
*/
