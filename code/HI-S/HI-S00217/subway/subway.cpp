#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q,k[510],x,y,vis[500510];
long long w[500010],d[500510];
vector<pair<int,long long> >v[500510];
void dij(int s){
	for(int i=1;i<=m+n;i++) d[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	priority_queue<pair<long long,int> >q;
	d[s]=0ll,q.push(make_pair(0ll,s));
	while(q.size()){
		int x=q.top().second;
		q.pop(),vis[x]=1;
		for(auto y:v[x]){
			if(d[y.first]>d[x]+y.second&&!vis[y.first]) d[y.first]=d[x]+y.second,q.push(make_pair(-d[y.first],y.first));
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++) scanf("%d%d",&x,&y),v[x].push_back(make_pair(m+i,(long long)y)),v[m+i].push_back(make_pair(x,(long long)y));
	}
	while(q--){
		scanf("%d%d",&x,&y);
		dij(x);
		printf("%lld\n",d[y]+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
