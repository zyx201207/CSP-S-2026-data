#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tt{
	int x,l;
};
int ca,n,m,T,d,k,a[500005],x,y,dis[505][505];
vector<tt> q[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ca>>n>>m>>d>>T;
	memset(dis,0x3f3f,sizeof(dis));
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k;dis[i][i]=0;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			q[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<q[i].size();j++){
			for(int k=j+1;k<q[i].size();k++){
				int x=q[i][j].x,y=q[i][k].x;
				dis[x][y]=dis[y][x]=q[i][j].l+q[i][k].l;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==k||i==j||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(T--){
		cin>>x>>y;
		int cnt=1e18;
		for(int i=0;i<q[x].size();i++){
			for(int j=0;j<q[y].size();j++){
				cnt=min(cnt,q[x][i].l+dis[q[x][i].x][q[y][j].x]+q[y][j].l);
			}
		}
		cout<<a[x]+a[y]+cnt<<'\n';
	}
	return 0;
} 
