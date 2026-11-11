#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sta,ed,sj,dqx,dqy;
int w[200005],k[500];
struct sub{
	int a,t;
}suw[500][500];
int wzb[500][500];
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
//	cout<<1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>suw[i][j].a>>suw[i][j].t;
//			for(int z=1;z<=j;z++){
//				wzb[suw[i][j-1].a][suw[i][j].a]=1;
//			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			//cin>>a[k[i]][j]>>t[k[i]][j];
//			cout<<wzb[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int zt=0;
	for(int i=1;i<=q;i++){
		cin>>sta>>ed;
		sj=0,zt=0;
		sj+=w[sta]+w[ed];
		for(int j=1;j<=n;j++){
			for(int z=1;z<=k[j];z++){
				if(suw[j][z].a==sta&&zt==0){
					dqx=j;
					dqy=z;
					zt=1;
					sj+=suw[dqx][dqy].t;
				}
				else if(suw[j][z].a==sta&&zt==1){
					if(suw[j][z].t<=suw[dqx][dqy].t){
						sj-=suw[dqx][dqy].t;
						dqx=k[j];
						dqy=z;
						sj+=suw[dqx][dqy].t;
					}
				}
				else if(suw[j][z].a==ed&&zt==1){
					sj+=suw[j][z].t;
				}
			}
		}
		cout<<sj<<endl;
	}
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
