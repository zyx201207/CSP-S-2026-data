#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,D=25,Q=1e5+5;
int n,m,d,q,c,x[Q],y[Q],k[N];
struct stu{
	int v,t;
};
vector<stu> a[N];
vector<stu> b[M];
int w[M],ans,flag[M];
void bfs(int k){
	for(int i=1;i<=m;i++){
		flag[i]=0;
	}
	ans=1e9+5;
	priority_queue< pair<int,int> > q;
	q.push({-1*w[x[k]],x[k]});
	while(!q.empty()){
		int w=-1*q.top().first,u=q.top().second;
		q.pop();
		if(u==y[k]){
			ans=min(ans,w);
		}
		if(flag[u]){
			continue;
		}
		flag[u]=1;
		for(int i=0;i<b[u].size();i++){
			int v=b[u][i].v,t=b[u][i].t;
			q.push({-1*(t+w),v});
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		//cin>>k[i];
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int v,t;
			scanf("%lld%lld",&v,&t);
			//cin>>v>>t;
			a[i].push_back({v,t});			
		}
	}
	for(int i=1;i<=q;i++){
		//cin>>x[i]>>y[i];
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
			if(a[i].size()==2){
				int u=a[i][0].v,v=a[i][1].v,w=a[i][0].t+a[i][1].t;
				b[u].push_back({v,w});
				b[v].push_back({u,w});
			}
	}
		for(int i=1;i<=q;i++){
			bfs(i);
			//cout<<ans+w[y[i]]<<endl;
			printf("%lld",ans+w[y[i]]);
			cout<<endl;
    	}
	return 0;
}

