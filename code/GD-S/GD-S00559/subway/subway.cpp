#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
long long dis[505][505],w[500005];
vector<pair<int,int> >g[500005];
long long rd(){
	char c=getchar();
	int x=0,y=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') y=-1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		w[i]=rd();
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		k=rd();
		for(int j=0;j<k;j++){
			int u,v;
			u=rd();
			v=rd();
			g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++){
//		cout<<"station "<<i<<":\n";
		for(auto j:g[i]){
			for(auto k:g[i]){
				if(j.first!=k.first){
//					cout<<"connecting "<<j.first<<" and "<<k.first<<endl;
					dis[j.first][k.first]=min(dis[j.first][k.first],(long long)j.second+k.second);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dis[i][k]==inf||dis[k][j]==inf) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		long long ans=LLONG_MAX;
		u=rd();
		v=rd();
		for(auto j:g[u]){
			for(auto k:g[v]){
				ans=min(ans,j.second+k.second+dis[j.first][k.first]);
			}
		}
		printf("%lld\n",w[u]+w[v]+ans);
	}
	return 0;
}
/*
n^3+d^2(m+q)
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/ 
