#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int c,n,m,d,q,w[N],a[510][N],t[510][N],k[510];
bool vis[510][N],ma[N];
int dfs(int l,int r){
	int mi=1e8;
	for(int i=1;i<=n;i++){//遍历线 
		if(vis[i][l]){
			if(vis[i][r]){
				mi=min(mi,t[i][l]+t[i][r]);
			}else{
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==l||ma[j]) continue;
					ma[a[i][j]]=1;
					mi=min(mi,t[i][l]+t[i][j]+dfs(a[i][j],r));
					ma[a[i][j]]=0;
				}
			}
		}
	}
	return mi;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);//第i条线有k[i]个站
		for(int j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]);//第i条线的第j个站是a[i][j]
			scanf("%d",&t[i][a[i][j]]);//从第i条线走到a[i][j]站要 t[i][a[i][j]]分钟 
			vis[i][a[i][j]]=1;//第i线有a[i][j]站 
		}
	}
	while(q--){
		memset(ma,0,m);
		int l,r;
		scanf("%d%d",&l,&r);
		ma[l]=1;
		cout<<dfs(l,r)+w[l]+w[r]<<endl;
	} 
	return 0;
}
