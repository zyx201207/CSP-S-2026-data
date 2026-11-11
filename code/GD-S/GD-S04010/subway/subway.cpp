#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long c,n,m,d,q;
long long w[N];
long long w1[N][25];
vector<int>line[25];
vector<int>vc[N];
struct node{
	int l,r,id,ans;
}qu[N];
int vis[N];
int dis[N];
bool cmp(node s1,node s2){
	return s1.l <s2.l ;
}
void dij(int st){
	priority_queue<pair<int,pair<int,int> > >q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	for(int i=0;i<vc[st].size();i++){
		int flag=0;
		for(int j=0;j<line[vc[st][i]].size();j++){
			int v=line[vc[st][i]][j];
			if(st==v){
				flag=1;
				continue;
			}
			if(flag==0) continue;
			dis[v]=w1[st][vc[st][i]]+w1[v][vc[st][i]];
			q.push({w1[st][vc[st][i]]+w1[v][vc[st][i]], { v,vc[st][i] } } );
		}
	}
	while(!q.empty()){
		pair<int,pair<int,int> >top=q.top();
		q.pop();
		int u=top.second.first;
		int linn=top.second.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<vc[u].size();i++){
			int lin=vc[u][i];
			if(lin==linn) continue;
			int flag=0;
			for(int j=0;j<line[lin].size();j++){
				int v=line[lin][j];
				if(u==v){
					flag=1;
					continue;
				}
				if(flag==0) continue;
				if(dis[v]>dis[u]+w1[u][lin]+w1[v][lin]) {
					dis[v]=dis[u]+w1[u][lin]+w1[v][lin];
					q.push({-dis[v],{v,lin}});
				}
			}
		} 
	} 
}
bool cnp(node s1,node s2){
	return s1.id <s2.id ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,a;
			cin>>x>>a;
			line[i].push_back(x);
			vc[x].push_back(i);
			w1[x][i]=a;
		}
	}
	vector<int>g;
	for(int i=1;i<=q;i++){
		cin>>qu[i].l >>qu[i].r ;
		qu[i].id =i;
		g.push_back(qu[i].l );
	}
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());
	sort(qu+1,qu+1+q,cmp);
	int j=1;
	for(int i=0;i<g.size();i++){
		dij(g[i]);
		while(qu[j].l ==g[i]){
			qu[j].ans=dis[qu[j].r ]+w[qu[j].l ]+w[qu[j].r ];
			j++;
		}
	}
	sort(qu+1,qu+1+q,cnp);
	for(int i=1;i<=q;i++){
		cout<<qu[i].ans <<endl;
	}
	return 0;
} 
