#include <bits/stdc++.h>
using namespace std;
/*
运用整体的思想,将每条线视作一个节点(因为在同一条线上的运动不计步行时间)
共有至多500条线
要找出换乘站
*/
const int N=505,M=5*1e5+5;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
int g[N][N],w[M];


struct s{
    int l,t;
};
//每站所在的线路和站台到站厅的时间
vector<s> b[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	memset(g,0x3f,sizeof(g));


	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
        g[i][i]=0;
	}
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        int cnt;
        cin>>cnt;
        for(int j=1;j<=cnt;j++){
            int a,ti;
            cin>>a>>ti;
            b[a].push_back({j,ti});

        }
	}

	for(int i=1;i<=m;i++){
        if(b[i].size()<2) continue;
        //换乘站

        for(s p1:b[i]){
            for(s p2:b[i]){
                g[p1.l][p2.l]=min(g[p1.l][p2.l],p1.t+p2.t);
            }
        }
	}

	//floyd算法
	for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
	}

	while(q--){
        long long res=0x3f3f3f3f3f3f3f3f;
        int x,y;
        cin>>x>>y;

        for(s p1:b[x]){
            for(s p2:b[y]){
                res=min(res,1ll*g[p1.l][p2.l]+p1.t+p2.t);
            }
        }
        cout<<res+w[x]+w[y]<<endl;
	}
	return 0;
}
