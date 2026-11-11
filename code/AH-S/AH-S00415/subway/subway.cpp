#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+5,M=2e4+5,D=20+5,Q=1e5+5,INF=0x3f3f3f3f3f3f3f3f;
int w[M];
int a[N][M];
int lis[M][D];
int nk[M];
int c,n,m,d,q;
struct Query{
	int l,r;
}ask[Q];
int ans[Q];
int f[N][N];
void Floyd(){
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int idx=1;idx<=m;idx++){//枚举站台 
		for(int i=1;i<=nk[idx];i++){
			for(int j=i+1;j<=nk[idx];j++){
				int al=lis[idx][i],ar=lis[idx][j];
				//cout<<al<<" "<<ar<<" "<<i<<" "<<j<<" "<<idx<<endl;
				int x=a[al][idx],y=a[ar][idx];
				//cout<<x<<" "<<y<<endl;
				f[al][ar]=f[ar][al]=(x+y);
			}
		}
	}//cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int u,x,y;
	for(int i=1;i<=n;i++){
		cin>>u;
		for(int j=1;j<=u;j++){
			cin>>x>>y;
			//x是站厅号，y是权重 
			a[i][x]=y;
			lis[x][++nk[x]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>ask[i].l>>ask[i].r;
	}
	Floyd();
	int b=0,l=0,r=0;
	int ansn=INF;
	for(int idx=1;idx<=q;idx++){
		ansn=INF;
		b=w[ask[idx].l]+w[ask[idx].r];
		l=ask[idx].l;r=ask[idx].r;
		for(int i=1;i<=nk[l];i++){
			
			for(int j=1;j<=nk[r];j++){
				int xa=lis[l][i],xb=lis[r][j];
				ansn=min(ansn,f[xa][xb]+a[xa][l]+a[xb][r]);
				
			}
		}
		cout<<ansn+b<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
