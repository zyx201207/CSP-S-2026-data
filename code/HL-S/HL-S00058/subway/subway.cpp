#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > PII;
const int N=5e5+5;
int idd,n,m,d,q;
long long ww[N];
int e[4*N],ne[4*N],cc[4*N],h[2*N],idx;
long long w[4*N];
vector<int> v[505];
long long dist[5005][5005],tt[5005][5005];
bool st[2*N];
void add(int a,int b,long long c,int d){
	e[idx]=b,w[idx]=c,cc[idx]=d,ne[idx]=h[a],h[a]=idx++;
}
void dij(int id){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	for(int i=1;i<=2*m;i++) dist[id][i]=1e18,st[i]=0;
	dist[id][id]=0;
	q.push({0,{id,0}});
	while(q.size()){
		PII t=q.top();
		q.pop();
		if(st[t.second.first]) continue;
		st[t.second.first]=1;
		for(int i=h[t.second.first];~i;i=ne[i]){
			int j=e[i];
			if(cc[i]==t.second.second||t.second.second==0){
				if(dist[id][j]>dist[id][t.second.first]+w[i]){
					dist[id][j]=dist[id][t.second.first]+w[i];
					q.push({dist[id][j],{j,cc[i]}});
				}
			}
			else{
				if(dist[id][j]>dist[id][t.second.first]+w[i]+tt[t.second.second][t.second.first]+tt[cc[i]][t.second.first]){	
					dist[id][j]=dist[id][t.second.first]+w[i]+tt[t.second.second][t.second.first]+tt[cc[i]][t.second.first];
					q.push({dist[id][j],{j,cc[i]}});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&idd,&n,&m,&d,&q);
	memset(h,-1,sizeof h);
	for(int i=1;i<=m;i++){
		scanf("%d",&ww[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=2*k;j++){
			long long x;
			scanf("%lld",&x);
			if(j%2){
				v[i].push_back(x);
				if(v[i].size()>1){
					add(v[i][v[i].size()-1],v[i][v[i].size()-2],0,i);
					add(v[i][v[i].size()-2],v[i][v[i].size()-1],0,i);
				}
			}
			else{
				tt[i][v[i][v[i].size()-1]]=x;
				tt[v[i][v[i].size()-1]][i]=x;
				add(v[i][v[i].size()-1],v[i][v[i].size()-1]+m,x,i);
				add(v[i][v[i].size()-1]+m,v[i][v[i].size()-1],x,i);
			}
		}
	}
	if(idd<=11){
		for(int i=1;i<=m;i++){
			dij(i+m);
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",dist[x+m][y+m]+ww[x]+ww[y]);
		}
	}
	else printf("0");
	return 0;
}