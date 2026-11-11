#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q;
long long w[500005];
long long k[505];
long long dis[500005];
bool b[500005];
long long cnt=0;
long long val[1000005],to[1000005],nxt[1000005],h[1000005];
void add(int a,int b,long long c){
	val[++cnt]=c;
	to[cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			long long a,t;
			cin>>a>>t;
			add(i+m,a,t);
			add(a,i+m,t);
		}
	}
	int x,y;
	while(Q--){
		cin>>x>>y;
		for(int i=1;i<=m+n;i++){
			dis[i]=2e18;
			b[i]=0;
		}
		dis[x]=0;
		q.push({0,x});
		while(!q.empty()){
			int k=q.top().second;
			q.pop();
			if(b[k]){
				continue;
			}
			b[k]=1;
			for(int i=h[k];i;i=nxt[i]){
				int ww=val[i],vv=to[i];
				if(dis[k]+ww<dis[vv]){
					dis[vv]=dis[k]+ww;
					q.push({dis[vv],vv});
				}
			}
		}
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
	return 0;
}
