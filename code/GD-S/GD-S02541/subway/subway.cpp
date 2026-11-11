#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> par;
const int MAXN=520,MAXM=5e5+7; 
ll dis[MAXN][MAXN],wi[MAXM];
map<ll,ll> wtime[MAXN];//wtime[i][j] i号线，j号站 时间 
vector<ll> cross[MAXM];
vector<ll> line[MAXN];
ll lst[MAXN],lp=0;
struct edge{
	ll nxt,v,w;
};
edge vec[MAXN*MAXN*2];
void add(int a,int b,int c){
	vec[++lp].v=b;
	vec[lp].w=c;
	vec[lp].nxt=lst[a];
	lst[a]=lp;
}
void dj(int s){
	priority_queue<par,vector<par>,greater<par> > q;
	dis[s][s]=0;
	q.push({0,s});
	ll u,v,w;
	while(!q.empty()){
		u=q.top().second;
		if(q.top().first>dis[s][u]){
			q.pop();
			continue;
		}
		q.pop();
		for(int i=lst[u];i!=0;i=vec[i].nxt){
			v=vec[i].v;
			w=vec[i].w;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
ll c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll k,a,t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wi[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		line[i].reserve(k+1);
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			line[i].push_back(a);
			wtime[i][a]=t;
			cross[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(ll u:line[i]){
			if(cross[u].size()>1){
			//	cout<<"cross:"<<u<<'\n';
				for(ll j:cross[u]){
					if(j==i)continue;
				//	printf("%d line--- %lld:%lld \n",i,u,wtime[i][u]);
				//	printf("%d line--- %lld:%lld \n",j,u,wtime[j][u]);
					add(i,j,wtime[i][u]+wtime[j][u]);
					//add(i,j,wtime[i][u]+wtime[j][u]); 下次迟早会建 
				}
			}
		}
	}
	memset(dis,127,sizeof(dis));
	for(int i=1;i<=n;i++){
		dj(i);
	}
	ll x,y,minn;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		minn=LONG_LONG_MAX;
		for(ll u:cross[x]){
			for(ll v:cross[y]){
				minn=min(minn,wtime[u][x]+dis[u][v]+wtime[v][y]);
			}
		}
		cout<<minn+wi[x]+wi[y]<<'\n';
	}
}
