#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,n,m,d,q,w[500005],a[505][505],t[505][505];
int g[505][505],gr[505][505],dist[505][3],li[50005][50];
const  int INF=0x3f3f3f;
/*
pair<int,int>fin(int x){
	int pi=-1,pj=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[ci][0];j++){
			if(a[i][j]=)
		}
	}
}*/
void prin() {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			if(i==j) {
				g[i][j]=w[i];
				continue;
			}
			for(int ci=1; ci<=n; ci++) {
				short bx=0,by=0,ex=0,ey=0;
				bool fe=0,fb=0;
				for(int cj=1; cj<=a[ci][0]; cj++) {
					if(i==a[ci][cj]) {
						fb=1;
						bx=ci;
						by=cj;
					}
					if(j==a[ci][cj]) {
						fe=1;
						ex=ci;
						ey=cj;
					}
				}
				if(fe&&fb) {
					g[i][j]=t[bx][by];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==0){
				g[i][j]=INF;
			}
		}
	}
}
bool check(int x){
	if(li[x][0]>1)return 1;
	return 0;
}
int ac(int x,int y) {
	
	if(x>y)swap(x,y);
	dist[x][1]=w[x];
	dist[x][2]=0;
	for(int i=1;i<=m;i++){
		if(i==x)continue;
		dist[i][1]=INF;
	}
	for(int i=x;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j || g[i][j]==INF)continue;
			if(dist[i][1]+g[i][j] < dist[j][1]){
				if(check(i)){
					bool k=1;int o=0;
					for(int ci=1;ci<=li[dist[i][2]][0];ci++){
						for(int cj=1;cj<=li[j][0];cj++){
							if(li[dist[i][2]][ci]==li[j][cj]){
								k=0;
								break;
							}
						}
					}
					for(int ci=1;ci<=li[dist[i][2]][0];ci++){
						for(int cj=1;cj<=li[i][0];cj++){
							if(li[dist[i][2]][ci]==li[i][cj]){
								o=li[i][cj];
								//cout<<"o:"<<o<<endl;
								break;
							}
						}
					}
					int te=0;
					for(int r=1;r<=m;r++){
						if(a[o][r]==i)te=r;
					}
					if(k){
						dist[j][1]=dist[i][1]+g[i][j]+t[o][te];
					}else{
						dist[j][1]=dist[i][1]+g[i][j];
					}
				}else{
					dist[j][1]=dist[i][1]+g[i][j];
				}
				dist[j][2]=dist[i][2]+1;
			}
			else continue;
		} 
	}
	int ans=dist[y][1]+w[y]+g[y][dist[y][2]];
	return ans;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];

	for(int i=1; i<=n; i++) { //xianlu
		int k;
		cin>>k;
		a[i][0]=k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
			li[a[i][j]][0]++;
			li[a[i][j]] [li[a[i][j]][0]]=i;
		}
	}
	/*for(int i=1;i<=m;i++){
		cout<<i<<':';
		for(int j=1;j<=li[i][0];j++){
			cout<<li[i][j];
		}
		cout<<endl;
	}*/
	prin();
	/*
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<g[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		cout<<ac(x,y)<<endl;
		/*
		for(int i=1;i<=m;i++){
			for(int j=1;j<=2;j++){
				cout<<dist[i][j]<<' ';
			}
			cout<<endl;
		}*/
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3
*/
