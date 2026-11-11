#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010;
int c,n,m,d,q,w[500500],t[N][N],dl[N][N];
map<int,int> qp[550];
vector<int> zx[5010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		int k;
		scanf("%lld",&k);
		for(int j = 1;j <= k;j++){
			int zt;
			scanf("%lld",&zt);
			zx[zt].push_back(i);
			qp[i][zt] = 1;
			scanf("%lld",&t[i][zt]);
		}
	}
	memset(dl,0x3f,sizeof(dl));
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 1;k <= m;k++){
				if(i == j) dl[i][j] = 0;
				else{
					if(i == k){
						dl[i][k] = 0;
					}else{
						for(int l = 0;l < zx[i].size();l++){
							if(qp[zx[i][l]][k] == 1){
								dl[i][k] = min(dl[i][k],t[zx[i][l]][i] + t[zx[i][l]][k]);
							}
						}
					}
					if(j == k){
						dl[k][j] = 0;
					}else{
						for(int l = 0;l < zx[k].size();l++){
							if(qp[zx[k][l]][j] == 1){
								dl[k][j] = min(dl[k][j],t[zx[k][l]][k] + t[zx[k][l]][j]);
							}
						}
					}
					dl[i][j] = min(dl[i][j],dl[i][k] + dl[k][j]);
				}
			}
		}
	}
	while(q--){
		int st,ed;
		scanf("%lld%lld",&st,&ed);
		cout<<dl[st][ed] + w[st] + w[ed]<<endl;
	}
	return 0;
}
