#include<bits/stdc++.h>
using namespace std;
const int N=600,M=5e5+10,Q=1e5+10;
int c,n,m,d,q,w[M],vis[30];
int k[N],a[M],t[M],x,y,tn[M][30][30];
vector<pair<int,int> >mp[M],mq[M];
struct data{
	int num,id,fa;
	long long dis;
	bool operator()(const data x,const data y){
		return x.dis>y.dis;
	}
};
long long dijskra(int s){
	vector<int>dist(M,-1);
	priority_queue<data,vector<data>,data>p;
	for(int i=0;i<mp[s].size();i++){
		int o=mp[s][i].second;
		p.push({s,o,0,tn[s][o][o]});
	}
	while(!p.empty()){
		int u=p.top().num,e=p.top().id,l=p.top().fa;
		long long d=p.top().dis;
		p.pop();
		if(u==y)return d;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i].first,f=mp[u][i].second;
			if(l==v)continue;
			long long cost=0;
			if(e==f)cost=d;
			else cost=d+tn[u][e][f];
			if(v==y)cost+=tn[v][f][f];
			p.push({v,f,u,cost});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			mq[a[j]].push_back({i,t[j]});
			if(j>=2){
				mp[a[j]].push_back({a[j-1],i});
				mp[a[j-1]].push_back({a[j],i});
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<mq[i].size();j++){
			for(int k=j;k<mq[i].size();k++){
				int u=mq[i][j].first,ut=mq[i][j].second;
				int v=mq[i][k].first,vt=mq[i][k].second;
				if(k!=j)tn[i][u][v]=tn[i][v][u]=ut+vt;
				if(k==j)tn[i][u][v]=ut;
			}
		}
	}
	while(q--){
		cin>>x>>y;
		dijskra(x);
		cout<<dijskra(x)+w[x]+w[y]<<endl;
	}
	return 0;
}
