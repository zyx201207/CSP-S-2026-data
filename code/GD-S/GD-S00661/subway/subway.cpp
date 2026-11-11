#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N],dis[N][N];
vector<int>a[N],t[N];
int idx[N];
map<int,int>pos[M];
vector<int>appear[M];
void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x),t[i].push_back(y);
			pos[x][i]=j-1;
			appear[x].push_back(i);
		}
	}
	memset(dis,0x3f,sizeof(dis));
}
void work(){
	init();
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int x:appear[i])idx[x]=pos[i][x];
		for(int j=0;j<appear[i].size();j++)for(int k=j+1;k<appear[i].size();k++){
			int x=appear[i][j],y=appear[i][k];
			dis[x][y]=dis[y][x]=min(dis[x][y],t[x][idx[x]]+t[y][idx[y]]);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int res=0x3f3f3f3f3f3f3f3f;
		for(int i:appear[x])for(int j:appear[y]){
			res=min(res,w[x]+w[y]+t[i][pos[x][i]]+t[j][pos[y][j]]+dis[i][j]);
		}
		cout<<res<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	work();
	return 0;
}
