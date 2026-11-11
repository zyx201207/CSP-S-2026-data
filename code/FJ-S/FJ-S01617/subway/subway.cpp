#include<bits/stdc++.h>
#define pii pair<long long,int>
#define N 501000
using namespace std;
long long c,n,m,d,q,f[N],w[N],k,a,t,ans,minn;
class node{
	public:
		int name,end,w,nw;
};
vector<pii >s[N];
vector<node>h[550];
inline int read(){
	int sum=0,b=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')sum=sum*10+ch-'0',ch=getchar();
	return sum*b;
}
long long djk(int s,int e,int x,int y){
	memset(f,0x3f3f3f3f,sizeof(f));
	priority_queue<pii,vector<pii >,greater<pii > >q;
	q.push({0,s});
	f[s]=0;
	while(!q.empty()){
		pii now=q.top();
		q.pop();
		if(now.first!=f[now.second])continue;
		int u=now.second;
		for(int i=0;i<h[u].size();i++){
			int v=h[u][i].end,W=h[u][i].w;
			if(h[u][i].name==x&&x==y)W=-h[u][i].w;
			else if(h[u][i].name==x)W=2*h[u][i].nw-W;
			else if(h[u][i].name==y)W=W-2*h[u][i].nw;
			if(f[v]>W+now.first){
				f[v]=W+now.first;
				if(v==e)break;
				q.push({f[v],v});
			}
		}
	}
	return f[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>c>>n>>m>>d>>q;
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
//		cin>>w[i];
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
//		cin>>k;
		for(int j=1;j<=k;j++){
//			cin>>a>>t;
			a=read();
			t=read();
			s[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			for(int k=0;k<j;k++){
				int u=s[i][j].first,v=s[i][k].first,uw=s[i][j].second,vw=s[i][k].second;
				node road;
				road.end=v,road.w=uw+vw,road.name=i,road.nw=vw;
				h[u].push_back(road);
				road.end=u,road.w=uw+vw,road.name=i,road.nw=uw;
				h[v].push_back(road);
//				cout<<"road "<<i<<" : "<<u<<" -> "<<v<<" : "<<uw+vw<<" , "<<-uw-vw<<" , "<<uw-vw<<" , "<<vw-uw<<"\n";
			}
		}
	}
	while(q--){
		int x=read(),y=read();
//		cin>>x>>y;
		minn=0x3f3f3f3f;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				int sx=s[x][i].first,sy=s[y][j].first;
				ans=s[x][i].second+s[y][j].second;
				if(sx!=sy){
					ans+=djk(sx,sy,x,y);
//					cout<<djk(sx,sy,x,y)<<"\n";
				}
				minn=min(minn,ans);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}
