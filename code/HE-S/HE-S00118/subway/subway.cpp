#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int c,n,m,d,q1;
int w[N],k[N];
int a[N][N];
int t[N][N];
vector<pair<int,int> > G[N];
int dis[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=0x3f3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
		sum+=w[i];
//		G[0].push_back({i,w[i]});
//		G[i].push_back({0,w[i]});
		dis[0][i]=w[i];
		dis[i][0]=w[i];
	}
	bool r1=true,r2=true;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
//			G[i].push_back({j,t[i][j]});
//			G[j].push_back({i,t[i][j]});
			dis[i][j]=t[i][j];
			dis[j][i]=t[i][j];
			sum+=t[i][j];
		}
	}
	for(int k1=1;k1<=n;k1++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				dis[i][j]=min(dis[i][j],dis[i][k1]+dis[j][k1]);
			}
		}
	}
	for(int i=1;i<=q1;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<endl;
	}
    //cout<<sum;
	return 0;
}

//屎山代码，求调！！！！！！！！ !!
