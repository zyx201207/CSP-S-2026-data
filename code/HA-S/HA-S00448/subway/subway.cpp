#include<bits/stdc++.h>
using namespace std;
long long a,ans,n,m,r,io,k,s,e,d,Q;
long long w[500505],A,T,dis[505005],b[505005];
long long to[1001005],val[1001005],h[1001005],nxt[1001005],cnt;
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > > q;
void add(int a,int b,int c){
	to[++cnt]=b;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
long long dij(long long s,long long e){
	for(int i=1;i<=n+m;i++){
		dis[i]=0x3fffffff;
		b[i]=0;
	}
	dis[s]=0;
	while(!q.empty()){
		q.pop();
	}
	q.push({s,0});
	while(!q.empty()){
		int k=q.top().first;
		q.pop();
		if(b[k]==1){
			continue;
		}
		b[k]=1;
		for(int j=h[k];j!=0;j=nxt[j]){
			int v=to[j];
			if(b[v]==0&&dis[v]>dis[k]+val[j]){
				dis[v]=dis[k]+val[j];
				q.push({v,dis[v]});
			}
		}
	}
	return dis[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>io>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>A>>T;
			add(m+i,A,T);
			add(A,m+i,T);
		}
	}
	while(Q--){
		cin>>s>>e;
		cout<<dij(s,e)+w[s]+w[e]<<"\n";
	}
	return 0;
}
