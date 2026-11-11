#include<bits/stdc++.h>
using namespace std;
long long dis[505][505];//¥”i~j∫≈œﬂ
long long cz[500005],w[500005],k[500005];
struct node{
	long long h,t;
};
vector<node> a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=4e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			a[x].push_back({i,t});
		}
	}
	for(int x=1;x<=m;x++){
		for(int i=0;i<a[x].size();i++)
		for(int j=i+1;j<a[x].size();j++){
			node k1=a[x][i],k2=a[x][j];
			long long res=min(dis[k1.h][k2.h],k1.t+k2.t);
			dis[k1.h][k2.h]=dis[k2.h][k1.h]=res;
		}
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				dis[i][j]=dis[j][i]=min({dis[i][j],dis[j][i],dis[i][o]+dis[o][j]});
			}
		}
	}
	int s,e;
	while(q--){
		cin>>s>>e;
		long long ans=4e18;
		for(int i=0;i<a[s].size();i++)
		for(int j=0;j<a[e].size();j++){
			long long res=a[s][i].t+dis[a[s][i].h][a[e][j].h]+a[e][j].t;
			ans=min(ans,res);
		}
		cout<<ans+w[s]+w[e]<<"\n";
	}
	return 0;
}

