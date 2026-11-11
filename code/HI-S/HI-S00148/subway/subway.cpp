#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<long long>l;
long long dis[505][505];
struct sta{int id;
	long long t;
};
vector<vector<sta> >g;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	l.assign(m+1,0);
	for(int i=1;i<=m;i++){
		cin>>l[i];
	}
	g.assign(m+1,{});
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;long long t;cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1LL<<60;
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(sta&j:g[i]){
			for(sta&k:g[i]){
				if(j.id==k.id)continue;
				dis[j.id][k.id]=min(dis[j.id][k.id],j.t+k.t);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue; 
			for(int j=1;j<=n;j++){
				if(j==i||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		long long minl=1LL<<60;
		for(sta&j:g[x]){
			for(sta&k:g[y]){
				long long sum=l[x]+l[y]+j.t+k.t;
				sum+=dis[j.id][k.id];
				minl=min(minl,sum);
			}
		}cout<<minl<<"\n";
	}
	return 0;
}
