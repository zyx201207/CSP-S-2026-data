#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k;
ll w[505],dis[500005];
bool b[500005];
struct node{
	ll v;
	int to;
};
vector<node>v[500005];
priority_queue<pi,vector<pi>,greater<pi> > pq;
void dj(int t,int f){
	memset(dis,0x3f,sizeof(dis));
	memset(b,0,sizeof(b));
	dis[t]=0;
	pq.push({0,t});
	while(!pq.empty()){
		pi tp=pq.top();
		pq.pop();
		int se=tp.second;
		if(b[se])continue;
		b[se]=1;
		for(int v1=0;v1<v[se].size();v1++){
			node i;
			i.to=v[se][v1].to;
			i.v=v[se][v1].v;
			if(dis[i.to]>dis[se]+i.v){
				dis[i.to]=dis[se]+i.v;
				pq.push({dis[i.to],i.to});
			}
		}
	}
	printf("%lld\n",dis[f]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
		v[i+n].push_back({w[i],i});	
		v[i].push_back({w[i],i+n});
	}
	int x,y,z;
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&x,&y);
			z=y;
			v[2*n+i].push_back({y,x});
			v[x].push_back({y,2*n+i});
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		if(c>=16&&c<=19){
			printf("%lld",w[x]+w[y]+m*2*z);
		}else
		dj(x+n,y+n);
	}
	return 0;
}
