#include<bits/stdc++.h>
#define ll long long
#define BUF (1<<20)
char buf[BUF],*p1,*p2;
#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,BUF,stdin)),p1==p2)?EOF:*p1++)
void read(int &x){
	char ch=gc();x=0;
	while(ch<'0'||ch>'9')ch=gc();
	while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=gc();
}
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
ll dis[N][N],ans;
vector<pair<int,int>>e[N],in[M];
void dij(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		pair<ll,int>u=q.top();
		q.pop();
		if(u.first>=dis[s][u.second])continue;
		dis[s][u.second]=u.first;
		for(pair<int,int>v:e[u.second])
			if(dis[s][v.first]==dis[0][0])
				q.push(make_pair(u.first+v.second,v.first));
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c),read(n),read(m),read(d),read(q);
	for(int i=1;i<=m;++i)
		read(w[i]);
	for(int i=1;i<=n;++i){
		read(k[i]);
		int a,t;
		for(int j=0;j<k[i];++j){
			read(a),read(t);
			in[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;++i)
		for(pair<int,int>v1:in[i])
			for(pair<int,int>v2:in[i])
				if(v1!=v2){
					int w=v1.second+v2.second;
					e[v1.first].push_back(make_pair(v2.first,w));
					e[v2.first].push_back(make_pair(v1.first,w));
				}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)
		dij(i);
	while(q--){
		int x,y;
		read(x),read(y),ans=~(1ll<<63);
		for(pair<int,int>v1:in[x])
			for(pair<int,int>v2:in[y])
				ans=min(ans,dis[v1.first][v2.first]+v1.second+v2.second);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
