#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0;
	int c=getchar(),f=0;
	while(c==' '||c=='\n'||c=='\r') c=getchar();
	if(c=='-') f=1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return (f?-x:x);
}
const int N=2e6+5;
int n,m,vis[N],dist[N],ans;
ll d,a[N],cnt[N];
vector<int> g[N];
void bfs(int s){
	queue<int> res;
	res.emplace(s);
	for(int i=1;i<=n;i++) vis[i]=cnt[i]=dist[i]=0;
	vis[s]=1,cnt[s]=1;
	while(res.size()){
		int u=res.front();
		res.pop();
		for(int v:g[u]){
			if(!vis[v]){
			  vis[v]=1,dist[v]=dist[u]+1,cnt[v]=cnt[u];
			  res.emplace(v); 
			}
			else if(dist[u]+1==dist[v]) cnt[v]+=cnt[u];
		}
	}
	for(int i=1;i<=n;i++){
	   if(cnt[i]==2) ++ans;
     }
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		int u,v;
		bool ok=1;
		for(int i=1;i<=n;i++){
		   a[i]=read();
		   if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ok=false;
	    }
	    if(ok){
	      ll sum=d/(a[2]-a[1]);
	      if(sum!=0&&sum!=1&&n>=sum*2-1) printf("%d\n",n-sum*2+1);
	      else printf("0\n");
	      continue;
		}
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++)
		   for(int j=i+1;j<=n;j++)
		      if(a[j]-a[i]<=d) g[i].emplace_back(j); 
		ans=0;
		for(int i=1;i<=n;i++) bfs(i);
		printf("%d\n",ans);
	}
	return 0;
}
