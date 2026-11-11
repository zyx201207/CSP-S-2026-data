//+20pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,cnt[N];
int dis[N];
bool f[N];
vector<pair<int,int> > G[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		G[i].push_back({i+m,x});
		G[i+m].push_back({i,x});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,b,t,t1;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			cnt[a]++;
			if(7<=c&&c<=11){
				if(j!=1){
					G[a+m].push_back({b+m,t+t1});
					G[b+m].push_back({a+m,t+t1});
				}
				t1=t;
			}else{
				if(j!=1){
					G[b+m+cnt[b]*m].push_back({a+m+cnt[a]*m,0});
					G[a+m+cnt[a]*m].push_back({b+m+cnt[b]*m,0});
				}
				G[a+m].push_back({a+m+cnt[a]*m,t});
				G[a+m+cnt[a]*m].push_back({a+m,t});
			}
			b=a;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(f,false,sizeof(f));
		if(7<=c&&c<=11){
			for(int i=1;i<=2*m;i++)dis[i]=1e18;
			dis[x]=0;
			for(int i=1;i<=2*m;i++){
				int mi=-1;
				for(int j=1;j<=2*m;j++){
					if(f[j])continue;
					if(mi==-1||dis[j]<dis[mi])mi=j;
				}
				f[mi]=true;
				for(auto j:G[mi]){
					int to=j.first,w=j.second;
					if(f[to])continue;
					dis[to]=min(dis[to],dis[mi]+w);
				}
			}
			cout<<dis[y]<<'\n';
		}else{
			for(int i=1;i<=22*m;i++)dis[i]=1e18;
			dis[x]=0;
			for(int i=1;i<=22*m;i++){
				int mi=-1;
				for(int j=1;j<=22*m;j++){
					if(f[j])continue;
					if(mi==-1||dis[j]<dis[mi])mi=j;
				}
				f[mi]=true;
				for(auto j:G[mi]){
					int to=j.first,w=j.second;
					if(f[to])continue;
					dis[to]=min(dis[to],dis[mi]+w);
				}
			}
			cout<<dis[y]<<'\n';
		}
	}
	return 0;
}
   