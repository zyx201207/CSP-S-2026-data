#include<bits/stdc++.h>
using namespace std;
#define N 510
#define M 500010
#define I (long long)1e18
int idx,e[M],ne[M],h[N];
long long s[M],w[M];
int c,n,m,d,qu;
map<int,map<int,int>>mp;
void add(int a,int b,long long c){
	if(mp.find(a)!=mp.end()&&mp[a].find(b)!=mp[a].end()){
		if(s[mp[a][b]]>c)s[mp[a][b]]=c;
		return;
	}
	else mp[a][b]=idx;
	e[idx]=b;
	s[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
	return;
}
struct p{
	int u;
	long long dis;
	bool operator>(const p& a)const{
		return dis>a.dis;
	}
};
struct p2{
	vector<int>v1;
	vector<long long>v2;
}o[500010];
long long dis[N][N];
bool vis[N];
priority_queue<p,vector<p>,greater<p> >q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(h,-1,sizeof h);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,a;
		long long t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			o[a].v1.push_back(i);
			o[a].v2.push_back(t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)o[i].v1.size();j++){
			for(int k=j+1;k<(int)o[i].v1.size();k++){	
				add(o[i].v1[j],o[i].v1[k],o[i].v2[j]+o[i].v2[k]);
				add(o[i].v1[k],o[i].v1[j],o[i].v2[j]+o[i].v2[k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=I;
			vis[j]=0;
		}
		dis[i][i]=0;
		q.push({i,0});
		while(q.size()){
			int u=q.top().u;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int j=h[u];~j;j=ne[j]){
				int v=e[j];
				if(dis[i][v]>dis[i][u]+s[j]){
					dis[i][v]=dis[i][u]+s[j];
					q.push({v,dis[i][v]});
				}
			}
		}
	}
	while(qu--){
		int x,y;
		long long minn=I;
		cin>>x>>y;
		for(int i=0;i<(int)o[x].v1.size();i++){
			for(int j=0;j<(int)o[y].v1.size();j++){
				minn=min(minn,o[x].v2[i]+dis[o[x].v1[i]][o[y].v1[j]]+o[y].v2[j]);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
} 

