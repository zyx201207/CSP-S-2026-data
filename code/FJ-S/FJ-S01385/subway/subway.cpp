#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8005,M=1e7+5;
int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N];
//int head[N],pos=0;
//struct node{
//	int to,next,val;
//}e[M];
//inline void add(int u,int v,int w){
//	pos+=1;
//	e[pos].next=head[u];
//	e[pos].to=v;
//	e[pos].val=w;
//	head[u]=pos;
//	return;
//}
int f[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;	
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=5005;i++){
		for(int j=1;j<=5005;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int p=1;p<=k[i];p++){
			int u=a[i][p];
			for(int q=1;q<=k[i];q++){
				int v=a[i][q];
				if(u==v) continue;
				//add(u,v,t[i][p]+t[i][q]);
				f[u][v]=t[i][p]+t[i][q];
				//cout << "init " << u << "->" << v << ":" << t[i][p]+t[i][q] << "\n";
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			//if(f[i][j]!=1e18)
//				cout << i << "->" << j << ":" << f[i][j] << "\n";
//		}
//		cout << "\n";
//	}
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+w[y]+f[x][y] << "\n";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
