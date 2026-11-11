#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define endl '\n'
using namespace std;
int n,c,m,d,q;
int qw[1001];
int a[1001][1001];
int w[500001];
int ans[1001];
//int fa[1001];
//struct node{
//	int next;
//	int w;
//	int p;
//}z[1001];
struct Node{
	int p;
	int t;
}k[501];
int x,y;
int p1,w1,p2,w2;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	FOR(i,1,m) cin>>w[i];
	if(c<=8){
		FOR(i,1,m) FOR(j,1,m) a[i][j]=1000000001;
		FOR(i,1,n) {
			cin>>x;
			FOR(j,1,x) cin>>k[j].p>>k[j].t;
			FOR(j,1,x) {
				FOR(o,1,x){
					if(o!=j){
						a[k[j].p][k[o].p]=min(a[k[j].p][k[o].p],k[j].t+k[o].t);
						a[k[o].p][k[j].p]=a[k[j].p][k[o].p];
					} 
				} 
			}
		}
		FOR(i,1,m){
			FOR(j,1,m){
				FOR(o,1,m){
					a[i][j]=min(a[i][j],a[i][o]+a[o][j]);
				}
			}
		}
		FOR(i,1,m){
			FOR(j,1,m){
	//			cout<<a[i][j]<<" ";
			}
	//		cout<<endl;
		}
		FOR(i,1,q){
			cin>>x>>y;
			cout<<a[x][y]+w[x]+w[y]<<endl;
		}
	}
	else if(c>=9&&c<=11){//一个环 
		FOR(i,1,m) FOR(j,1,m) a[i][j]=1000000001;
		FOR(i,1,n){
			cin>>x;
			cin>>p1>>w1>>p2>>w2;
			a[p1][p2]=w1+w2;
			a[p2][p1]=w2+w1;
			qw[p1]++;
			qw[p2]++;
		}
		if(n==m){//环 
			FOR(i,1,m) ans[i]=1000000001;
			int pn=1;
			int pl=0;
			FOR(ee,1,n){
				FOR(i,1,n){
					if(a[pn][i]<=10000000&&i!=pl){
						ans[i]=min(ans[pn]+a[i][pn],ans[i]);
						pl=pn;
						pn=i;
						if(pn!=1) break;
					}
				}
			}
			FOR(i,1,q){
				cin>>x>>y;
				cout<<abs(ans[x]-ans[y])+w[x]+w[y]<<endl;
			}
		}
		else {//线 
			int pn;//现在的站点 
			FOR(i,1,n){
				if(qw[i]==1) {
					pn=i;
					break;
				}
			}
			int pl=0;//上一个来的站点 
			int pk;
			FOR(ee,1,n-1){
				FOR(i,1,n){
					if(a[pn][i]<=10000000&&i!=pl){
						ans[i]=ans[pn]+a[i][pn];
						pl=pn;
						pn=i;
						break;
					}
				}
			}
			FOR(i,1,q){
				cin>>x>>y;
				cout<<abs(ans[x]-ans[y])+w[x]+w[y]<<endl;
			}
		} 
	}
	return 0;
}
/*
dijkstra(链式前向星，空间？) 
1.floyd?(32pts)
2.判断环的情况(12pts) 


*/

