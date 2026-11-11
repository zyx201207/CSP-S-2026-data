#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N],a[505][20005],t[505][20005],k[N],dis[N],sum[N],sum2[N]; 
vector<pair<int,int> >e[N];
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		auto k=q.top();
		q.pop();
		if(dis[k.second]<k.first)continue;
		for(auto i:e[k.second]){
			if(dis[i.first]>dis[k.second]+i.second){
				dis[i.first]=dis[k.second]+i.second;
				q.push({dis[i.first],i.first});
			} 
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<k[i];j++){
			e[a[i][j]].push_back({a[i][j+1],t[i][j]+t[i][j+1]});
			e[a[i][j+1]].push_back({a[i][j],t[i][j]+t[i][j+1]}); 
			sum[j+1]=t[i][j]+t[i][j+1];
		}
		for(int j=k[i];j>=2;j--){
			e[a[i][j]].push_back({a[i][j-1],t[i][j]+t[i][j-1]});
			e[a[i][j-1]].push_back({a[i][j],t[i][j]+t[i][j-1]}); 
			sum2[j-1]=t[i][j]+t[i][j-1];
		}
		for(int j=1;j<=k[i];j++)for(int p=j+2;p<=k[i];p++){
			e[a[i][j]].push_back({a[i][p],sum[p-1]+t[i][p-1]+t[i][p]});
			e[a[i][p]].push_back({a[i][j],sum[p-1]+t[i][p-1]+t[i][p]});
			sum[p]=sum[p-1]+t[i][p-1]+t[i][p];
		}
		for(int j=1;j<=k[i];j++)for(int p=j-2;p>=1;p--){
			e[a[i][j]].push_back({a[i][p],sum2[p-1]+t[i][p+1]+t[i][p]});
			e[a[i][p]].push_back({a[i][j],sum2[p-1]+t[i][p+1]+t[i][p]});
			sum2[p]=sum2[p+1]+t[i][p+1]+t[i][p];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<w[u]+w[v]+dis[v]<<'\n';
	}
	return 0;
} 


