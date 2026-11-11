#include <bits/stdc++.h>
using namespace std;

const int N=11;

int n,c,t,k,cnt,f[N],dis[N];
vector<int>g[N];

int find(int x){
	return (f[x]==x)?x:f[x]=find(f[x]);
}

void merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v)f[u]=v;
}

int calc(){
	iota(f+1,f+n+1,1); 
	int res=0;
	for(int i=1;i<=n;++i)
		for(int v:g[i])
			if((cnt>>(i-1)&1)&&(cnt>>(v-1)&1))
				merge(i,v);
	for(int i=1;i<=n;++i)
		if((cnt>>(i-1)&1)&&i==f[i])++res;
	return res;
}

int bfs(int x){
	memset(dis,0x3f,sizeof dis);
	queue<int>q;
	q.push(x);
	dis[x]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if((cnt>>(u-1)&1))return dis[u];
		for(int v:g[u]){
			if(dis[v]==0x3f3f3f3f){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans=1e9;
		for(cnt=1;cnt<(1<<n);++cnt)
			if(__builtin_popcount(cnt)==k){
					//cout<<cnt<<" "<<calc()<<"\n"; 
				if(calc()<=2){
					int res=0;
					for(int i=1;i<=n;++i){
						res=max(res,bfs(i));
					}
					ans=min(ans,res);
				}
			}
		cout<<ans<<"\n";
	}
}
