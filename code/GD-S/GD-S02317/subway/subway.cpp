#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[500005];
int dis[505][505];
vector<int>a[505];
vector<int>t[505];
vector<pair<int,int>>belong[5000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			belong[x].push_back({i,y});
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		map<int,int>vis;
		for(int j=0;j<k[i];j++){
			vis[a[i][j]]=t[i][j];
		}
		for(int j=i+1;j<=n;j++){
			for(int l=0;l<k[j];l++){
				if(vis[a[j][l]]){
					dis[i][j]=dis[j][i]=min(dis[i][j],vis[a[j][l]]+t[j][l]);
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=4557430888798830399;
		for(auto i:belong[x]){
			for(auto j:belong[y]){
				minn=min(minn,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
}  
