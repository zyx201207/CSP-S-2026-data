#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=5e2+5;//站台数与线路数 
ll c,n,m,d,q,W[N],dis[M][M];
struct Edge{
	ll to,w;
};
vector<Edge> st[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;//n:线路数 m:站台数 
	for(int i=1;i<=m;i++) cin >> W[i];
	for(int i=1;i<=n;i++){//枚举线路 
		int ki;
		cin >> ki;
		for(int j=1;j<=ki;j++){
			int ai,ti;
			cin >> ai >> ti;
			st[ai].push_back({i,ti});//由站台向线路建边 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=100000000000000;//初始化各个线路之间的距离 5e2*2e9=1e12 1e14作冗余
		}
	}
	for(int i=1;i<=m;i++){//枚举每个站台连接的线路 
		int sz=st[i].size();
		for(int j=0;j<sz-1;j++){
			for(int k=j+1;k<sz;k++){//两两松弛这些线路 
				ll st1=st[i][j].to,st2=st[i][k].to,w1=st[i][j].w,w2=st[i][k].w;
				dis[st1][st2]=min(dis[st1][st2],w1+w2);
				dis[st2][st1]=min(dis[st2][st1],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){//Floyd启动！希望我没写错，因为这个被卡真得跳了 
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << "i:" << i << " j:" << j << " dis:" << dis[i][j] << endl;
		}
	}*/
	for(int i=1;i<=q;i++){//处理每个询问 
		int x,y;
		ll ans=100000000000000;
		cin >> x >> y;
		int xsz=st[x].size(),ysz=st[y].size();
		for(int j=0;j<xsz;j++){//枚举站点x的线路 
			int st1=st[x][j].to,w1=st[x][j].w;
			for(int k=0;k<ysz;k++){//枚举站点y的线路 
				int st2=st[y][k].to,w2=st[y][k].w;
				ans=min(ans,W[x]+w1+dis[st1][st2]+w2+W[y]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
