#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=502,M=5e5+2;
int op,n,m,k,d,_,x,s,t;
ll w[M],dis[M];
vector<pair<int,ll>>g[N];
unordered_map<int,vector<pair<int,ll>>>mp;
void bfs(){
	queue<int>q;
	q.push(s),memset(dis,0x3f,sizeof(dis)),dis[s]=0;
	while(!q.empty()){
		int x=q.front(); q.pop();
		if(x==t) continue;
		for(auto i:mp[x])
			for(auto j:g[i.fi])
				if(dis[x]+i.se+j.se<dis[j.fi])
					dis[j.fi]=dis[x]+i.se+j.se,q.push(j.fi);
	}
}
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d\n",&op,&n,&m,&d,&_);
	for(int i=1;i<=m;++i) scanf("%lld ",&w[i]);
	for(int i=1;i<=n;++i){
		cin>>k;
		while(k--) cin>>x>>t,mp[x].push_back({i,t}),g[i].push_back({x,t});
	}
	while(_--){
		scanf("%d %d",&s,&t);
		bfs(),printf("%lld\n",dis[t]+w[s]+w[t]);
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
