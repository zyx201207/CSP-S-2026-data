#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],dd[55][55][55][55]={},s[55][55]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		long long x,y,z;
		scanf("%lld",&x);
		for(int j=1;j<=x;j++){
			scanf("%lld%lld",&y,&z);
			s[y][i]=1;
			dd[y][i][y][0]=z;
			dd[y][0][y][i]=z;
		}
	}
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				for(int h=0;h<=m;h++){
					if(dd[i][j][k][h]!=0){
						continue;
					}
					if(j==h&&s[i][j]==1&&s[k][h]==1){
						dd[i][j][k][h]=0;
					}else{
						dd[i][j][k][h]=1e10;
					}
				}
			}
		}
	}
	for(int s=0;s<=m;s++){
		for(int gg=0;gg<=m;gg++){
			for(int i=0;i<=m;i++){
				for(int j=0;j<=m;j++){
					for(int k=0;k<=m;k++){
						for(int h=0;h<=m;h++){
//							if(dd[i][j][k][h]==1e10)continue;
							dd[i][j][k][h]=min(dd[i][j][k][h],dd[i][j][s][gg]+dd[s][gg][k][h]);
						}
					}
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<dd[i][0][j][0]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		long long tp=w[x]+w[y]+dd[x][0][y][0];
		printf("%lld\n",tp);
	}
	return 0;
}

