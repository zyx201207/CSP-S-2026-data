#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=1e4+5;
struct node{
	ll to,dis;
};
ll c,n,m,d,q;
ll w[M],dis[M][M],zhan[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int to,times;
			cin>>to>>times;
			dis[i][to]=times;
			dis[to][i]=times;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		int pian=rand()%d;
		cin>>x>>y;
		cout<<dis[x][y]+(w[x]+w[y])+pian<<"\n";
	}
	return 0;
}
