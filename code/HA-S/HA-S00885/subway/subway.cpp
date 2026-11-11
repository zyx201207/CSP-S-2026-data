#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
long long k[505];
struct di{
	long long a,t;
};
vector<di>l[505];
long long a[505][505];
vector<pair<long long,long long> >vis[500005];
bool cmp(di x,di y){
	return x.a<y.a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long u,w;
			cin>>u>>w;
			vis[u].push_back(make_pair(i,w));
			l[i].push_back({u,w});
		}
		sort(l[i].begin(),l[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(long long i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long x=0,y=0;
			long long fl=0x3f3f3f3f3f3f3f3f;
			while(x<k[i] && y<k[j]){
				if(l[i][x].a==l[j][y].a){
					if(fl>l[i][x].t+l[j][y].t){
						fl=l[i][x].t+l[j][y].t;
					}
					x++;y++;
				}else if(l[i][x].a<l[j][y].a){
					x++;
				}else if(l[i][x].a>l[j][y].a){
					y++;
				}
			}
			a[i][j]=fl;
			a[j][i]=fl;
		}
	}
	
	for(long long t=1;t<=n;t++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i!=j && j!=t && t!=i){
					a[i][j]=min(a[i][j],a[i][t]+a[t][j]);
				}
			}
		}
	}
	for(long long c=1;c<=q;c++){
		long long u,v;
		cin>>u>>v;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(long long i=0;i<vis[u].size();i++){
			for(long long j=0;j<vis[v].size();j++){
				ans=min(ans,a[vis[u][i].first][vis[v][j].first]+vis[u][i].second+vis[v][j].second);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
