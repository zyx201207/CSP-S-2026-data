#include<bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
int w[500005];
struct ee{
	int line;
	int t;
};
vector<ee>edge[500005];
int dis[505][505];
const int inf=1000000000000000000ll;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++){
			int vv,ww;
			cin>>vv>>ww;
			edge[vv].push_back((ee){i,ww});
		}
	}

	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int kkk=edge[i].size();
		for(int j=0;j<kkk;j++){
			for(int k=0;k<kkk;k++){
				int u=edge[i][j].line;
				int v=edge[i][k].line;
				int uw=edge[i][j].t;
				int vw=edge[i][k].t;
				if(u==v)dis[u][v]=0;
				else dis[u][v]=uw+vw;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	

	for(int tt=1;tt<=q;tt++){
		int fr,ed;
		cin>>fr>>ed;
		int kfr=edge[fr].size();
		int ked=edge[ed].size();
		int res=inf;
		for(int i=0;i<kfr;i++){
			for(int j=0;j<ked;j++){
				res=min(res,dis[edge[fr][i].line][edge[ed][j].line]+edge[fr][i].t+edge[ed][j].t);
				//cout<<"dis "<<edge[fr][i].line<<"~"<<edge[ed][j].line<<" is "<<dis[edge[fr][i].line][edge[ed][j].line]<<"\n";
			}
		}
		res+=w[fr]+w[ed];
		cout<<res<<"\n";
	}

	return 0;
}