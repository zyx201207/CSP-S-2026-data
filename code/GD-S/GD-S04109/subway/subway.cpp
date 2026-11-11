#include<bits/stdc++.h>
#define int long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=2010,M=5e5+10;
int c,n,m,d,q,w[M],k,x,y;
vector<pair<int,int> >a[M];
int f[N][N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#if LOCAL 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#endif
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=(i==j?0:LLONG_MAX);
	}
	for(int i=1;i<=m;i++){
		int len=a[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				int x=a[i][j].first,y=a[i][k].first,w=a[i][j].second+a[i][k].second;
				f[x][y]=min(f[x][y],w);
				f[y][x]=min(f[y][x],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]==LLONG_MAX||f[k][j]==LLONG_MAX)continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<' ';
//		}cout<<'\n';
//	}
	while(q--){
		cin>>x>>y;
		int lenx=a[x].size(),leny=a[y].size(),ans=LLONG_MAX;
		for(int i=0;i<lenx;i++){
			for(int j=0;j<leny;j++){
				int px=a[x][i].first,py=a[y][j].first,pw=a[x][i].second+a[y][j].second;
				ans=min(ans,pw+f[px][py]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
