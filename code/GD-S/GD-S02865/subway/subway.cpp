#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=500,mm=5e5,mq=1e5;
const int maxn=mn+10,maxm=mm+20+mn,maxq=mq+10;
int c,n,m,d,qq,t[maxm],ans[maxq],s[maxq],to[maxq];
struct data{
	int v,w;
	bool operator<(const data&s)const{return s.w<w;}
};vector<data>mp[maxm];
void add(int u,int v,int w){
	mp[u].push_back({v,w});
}void dj(int ooo){
	int ss=s[ooo];
	int dis[maxm];bool vis[maxm];
	for(int i=0;i<=n+m;i++)dis[i]=-1,vis[i]=false;
	priority_queue<data>q;q.push({ss,0});
	while(!q.empty()){
		data now=q.top();q.pop();
		if(vis[now.v])continue;
		vis[now.v]=true;int nows=mp[now.v].size();
		for(int i=0;i<nows;i++){
			data flag=mp[now.v][i];
			if(vis[flag.v])continue;
			dis[flag.v]=flag.w+now.w;
			q.push({flag.v,dis[flag.v]});
		}
	}for(int i=ooo;i<=qq;i++)if(s[i]==s[ooo])ans[i]=dis[to[i]]+t[s[i]]+t[to[i]];
}signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;cin>>v>>w;
			add(i+m,v,w);add(v,i+m,w);
		}
	}for(int i=1;i<=qq;i++)ans[i]=-1;
	for(int i=1;i<=qq;i++)cin>>s[i]>>to[i];
	for(int i=1;i<=qq;i++)if(ans[i]==-1)dj(i);
	for(int i=1;i<=qq;i++)cout<<ans[i]<<'\n';
	return 0;
}
