#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define p pair<ll,ll>
#define fs first
#define sc second
priority_queue<p,vector<p>,greater<p> >q;
ll n,m,d[500501],w[500501],cnt,qun,x,y,v[500501],t;
vector<p>g[500501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>qun>>qun;
	for(ll i=1;i<=m;i++) scanf("%lld",w+i);
	cnt=m;
	for(ll i=1,k,a,t;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			g[a].push_back({++cnt,t});
			g[cnt].push_back({a,t});
			if(j>1){
				g[cnt-1].push_back({cnt,0});
				g[cnt].push_back({cnt-1,0});
			}
		}
	}
	while(qun--){
		scanf("%lld%lld",&x,&y);
		q.push({0,x});
		memset(d,67,sizeof d);
		memset(v,0,sizeof v);
		d[x]=0;
		while(q.size()){
			t=q.top().sc;
			q.pop();
			if(v[t]) continue;
			v[t]=1;
			for(p i:g[t]) if(d[t]+i.sc<d[i.fs]){
				d[i.fs]=d[t]+i.sc;
				q.push({d[i.fs],i.fs});
			}
		}
		printf("%lld\n",d[y]+w[x]+w[y]);
	}
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
