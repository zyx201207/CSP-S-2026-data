#include<bits/stdc++.h>
#define pilr pair<int,ll>
#define f first
#define s second

using namespace std;
using ll=long long;
const int N=503;
const int M=5e5+5; 

int c,n,m,d,q,u,v,num;
ll w[M],way[N][N];
vector<pilr> graph[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(way,0x3f,sizeof(way));
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){	
			cin>>u>>v;
			graph[u].emplace_back(make_pair(i,v));
		}
		way[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(pilr a:graph[i])
			for(pilr b:graph[i])
				if(a.f!=b.f)
					way[a.f][b.f]=way[b.f][a.f]=min(way[a.f][b.f],a.s+b.s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				way[j][k]=min(way[j][k],way[j][i]+way[i][k]);
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ll ans=LLONG_MAX;
		for(pilr a:graph[u])
			for(pilr b:graph[v])
				ans=min(ans,a.s+b.s+way[a.f][b.f]);
		cout<<ans+w[u]+w[v]<<"\n"; 
	}
	return 0;
} 
