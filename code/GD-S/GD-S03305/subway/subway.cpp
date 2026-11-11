#include<bits/stdc++.h>
#define int long long
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
int c,n,m,d,q,w[500005],dis[505][505];
vector<pii> st[500005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=500;i++) {
		for(int j=1;j<=500;j++) {
			dis[i][j]=1e16;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1,k,a,t;i<=n;i++) {
		dis[i][i]=0;
		cin>>k;
		while(k--) {
			cin>>a>>t;
			st[a].push_back(mp(i,t));
		}
	}
	for(int i=1;i<=m;i++) {
		int cnt=st[i].size();
		for(int j=0;j<cnt;j++) {
			for(int k=0;k<j;k++) {
				pii jj=st[i][j],kk=st[i][k];
				dis[jj.first][kk.first]=dis[kk.first][jj.first]=min(dis[jj.first][kk.first],jj.second+kk.second);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) {
		int x,y,ans=numeric_limits<int>::max();
		cin>>x>>y;
		for(int i=0;i<st[x].size();i++) {
			for(int j=0;j<st[y].size();j++) {
//				if(dis[st[x][i].first][st[y][j].first]<ans) {
//					cout<<st[x][i].first<<' '<<st[y][j].first<<'\n';
//					cout<<dis[st[x][i].first][st[y][j].first]<<'\n';
//				}
				ans=min(ans,dis[st[x][i].first][st[y][j].first]+st[x][i].second+st[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
//		cout<<'\n';
	}
	return 0;
}
