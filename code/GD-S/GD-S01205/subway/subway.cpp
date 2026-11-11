#include<bits/stdc++.h>
using namespace std;
const long long N=6e5+5;
long long countt;
//pair<long long,long long>;
//开long long !!!!!!!!!!!!!!!!!//开long long !!!!!!!!!!!!!!!!!
//开long long !!!!!!!!!!!!!!!!!//开long long !!!!!!!!!!!!!!!!!
long long m,n,k[N],c,dd,q,d[505][505],di[N],vis[N];
vector<pair<long long,long long> >ve[N];
long long cnt;
void dij(long long st){
	for(long long i=1;i<=cnt;i++)di[i]=1e18,vis[i]=0;
	priority_queue<pair<long long,long long> >q;
	q.push({0,st});
	di[st]=0;
	while(!q.empty()){
//		if(countt++>1e8){
//			cout<<"&&&&&";
//			return;
//		}
		long long u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
//		for(long long i=1;i<=m;i++){
//			printf("di[%d]:%d ",i,di[i]);
//		}
//		printf("\n");
		for(pair<long long,long long> to:ve[u]){
			long long v=to.first,w=to.second;
			//if(v<=m)printf("66666666 u:%d v:%d w:%d di[u]:%d di[v]:%d\n",u,v,w,di[u],di[v]);
			if(di[v]>di[u]+w){
				di[v]=di[u]+w;
				q.push({-di[v],v});
				//printf("di[%d]:%d\n",v,di[v]);
				
			}
			//printf("u:%d v:%d\n",u,v);
		}
	}
	for(long long i=1;i<=m;i++){
		d[st][i]=di[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	
		for(long long i=1,v21;i<=m;i++){
		scanf("%lld",&v21);
		ve[i].push_back({m+i,v21});
		ve[m+i].push_back({i,v21});
	}
	
	cnt=2*m;
	for(long long i=1,k,v,w;i<=n;i++){
		scanf("%lld",&k);cnt++;
		while(k--){
			long long last=0;
			scanf("%lld%lld",&v,&w);
			
			ve[cnt].push_back({v+m,w});
			ve[v+m].push_back({cnt,w});
			
		}
	}

	for(long long i=1;i<=m;i++){
		dij(i);
	}

	for(long long i=1,l,r;i<=q;i++){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",d[l][r]);
	}
	
	
	return 0;
}

