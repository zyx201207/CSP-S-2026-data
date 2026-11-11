#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
using namespace std;
int c,n,m,d,q,w[500005],ans[500005];
struct node{
	int v,t;
};
vector<vector<node>>g;
vector<vector<bool>>f;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int spfa(int s,int e){
	vector<int>dis(m+5,0x3f3f3f3f3f3f3f3f),cnt(m+5,0);
	vector<bool>vis(m+5,0);
	queue<pii>q;
	q.push({s,0});
	vis[s]=1,dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		int u=q.front().first,lst=q.front().second;
		q.pop();
		vis[u]=0;
		for(auto &i:g[u]){
			int v=i.v,t=i.t;
			int ds=dis[u]+t+2*w[u];
			if(lst!=0){
				if(!f[lst][v])ds+=w[v];
			}
			if(cnt[v]<d&&dis[v]>ds){
				dis[v]=ds,cnt[v]++;
				if(!vis[v]){
					q.push({v,u});
					vis[v]=1;
				}
			}
		}
	}
	int ds=dis[e];
	dis.clear(),cnt.clear(),vis.clear();
vector<int>().swap(dis),vector<int>().swap(cnt),vector<bool>().swap(vis);
	return ds;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	c=read(),n=read(),m=read(),d=read(),q=read();
	g.resize(m+1,vector<node>());
	f.resize(m+1,vector<bool>(m+1,0));
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		vector<int>a(k+1),t(k+1);
		for(int j=0;j<k;j++)a[j]=read(),t[j]=read();
		for(int j=0;j<k-1;j++)g[a[j]].push_back({a[j+1],t[j+1]});
		for(int j=0;j<k;j++)for(int l=j+1;l<k;l++)f[a[j]][a[l]]=1;
		a.clear(),t.clear();
		vector<int>().swap(a),vector<int>().swap(t);
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<": ";
//		for(auto &j:g[i])cout<<j.v<<"-";
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		cout<<spfa(x,y)+2<<endl;
	}
	return 0;
} 
