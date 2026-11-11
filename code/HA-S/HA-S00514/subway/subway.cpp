#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int c,n,m,d,q1,s,f,j,x;
struct node{
	int e;
};
node no[N];
vector<pair<int,int> > g[N],g2[N];
vector<int> g3[N];
int dis[N],h[N];
int a1[N];
bool vis[N];
void spfa(int start){
	int s1=q1;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=0; i<g[cur].size(); i++){
			int v=g[cur][i].first;
			int e=g[cur][i].second;
			int u=g2[cur][i].second;
			int c=g3[s1][no[cur].e];
			if(u==s1 && dis[v]>dis[cur]+e){
				dis[v]=dis[cur]+e;
			    if(!vis[v]){
				   q.push(v);
				   vis[v]=1;
			    }
			}
			else if(u!=s1 && dis[v]>dis[cur]+e+a1[cur]){
				s1=u;
				dis[v]=dis[cur]+e+a1[cur];
			    if(!vis[v]){
				   q.push(v);
				   vis[v]=1;
			    }
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q1);
    for(int p=1; p<=m; p++){
    	scanf("%lld",&a1[p]);
	}
    for(int p=0; p<n; p++){
    	int t=0;
    	scanf("%lld",&t);
    	for(int i=0; i<2*t; i++){
    		scanf("%lld",&h[i]);
		}
		for(int i=0; i<t-1; i+=2){
			no[h[i]].e=(i+2)/2;
			g3[p+1].push_back(h[i+1]);
			g[h[i]].push_back({h[i+2],h[i+1]});
			g2[h[i]].push_back({h[i+2],p+1});
		}
	}
	for(int r=0; r<q1; r++){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		scanf("%lld%lld",&s,&f);
		dis[s]=a1[s];
		vis[s]=1;
		spfa(s);
		printf("%lld\n",dis[f]+a1[f]);
	}
	return 0;
}
