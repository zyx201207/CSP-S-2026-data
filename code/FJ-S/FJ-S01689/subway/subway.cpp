#include<bits/stdc++.h>
using namespace std;
const int maxn = 13000;
const int INF = 0x3f3f3f;
int c,n,m,d,q;
int w[maxn];
vector<pair<int,int>>f[maxn];
int T[maxn][maxn];
bool A[maxn][maxn];
int dis[maxn][maxn];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			A[j][a]=true;
			A[a][j]=true;
			T[j][a]=t;
			T[a][j]=t;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			dis[i][j]=dis[j][i]=INF;
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int q=1;q<=n;q++){
				if(A[i][q]==true&&A[q][j]==true){
					dis[i][j]+=(T[i][q]*2);
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]+T[x][y]*2<<"\n";
	}
	return 0;
}

