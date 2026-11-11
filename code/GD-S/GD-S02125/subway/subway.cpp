#include<bits/stdc++.h>
#define int long long
#define fr first
#define sd second 
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int maxm=5e5+5,maxn=505;
int cid,n,m,d,q,w[maxm],dis[maxn][maxn],k[maxn];
vector<pair<int,int>> vt[maxm];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	IOS
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,tt1,tt2;j<=k[i];j++){
			cin>>tt1>>tt2;
			vt[tt1].push_back({i,tt2});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=0;j<vt[i].size();j++){
			for(int tt=j+1;tt<vt[i].size();tt++){
				auto u=vt[i][j],v=vt[i][tt];
				dis[u.fr][v.fr]=min(dis[u.fr][v.fr],u.sd+v.sd);
				dis[v.fr][u.fr]=min(dis[v.fr][u.fr],u.sd+v.sd);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int tt=1;tt<=n;tt++){
				dis[j][tt]=min(dis[j][tt],dis[j][i]+dis[i][tt]);
			}
		}
	}
	int u,v;
	while(q--){
		cin>>u>>v;
		int ans=4e18;
		for(int i=0;i<vt[u].size();i++){
			for(int j=0;j<vt[v].size();j++){
				auto tu=vt[u][i],tv=vt[v][j];
//				printf("tu:%lld,%lld tv %lld,%lld curans:%lld\n",tu.fr,tu.sd,tv.fr,tv.sd,dis[tu.fr][tv.fr]+tu.sd+tv.sd);
				ans=min(ans,dis[tu.fr][tv.fr]+tu.sd+tv.sd);
			}
		}
		cout<<(ans+w[u]+w[v])<<"\n";
	} 
	return 0;
}

