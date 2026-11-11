//刘骏瑞 贵阳市清华中学 GZ-S00363 
#include<bits/stdc++.h>
using namespace std;
int tdk[500005],tdz[500005][501];
int c,n,m,d,q;
int zx[500005][501];
int xz[501][500005];
int zs[501];
bool vis[501][501];
int mq[501];
long long minn=1e9; 
void dfs(int now,int end,long long time){
	if(now==end){
		minn=min(minn,time+tdk[end]);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(zx[now][i]!=0){
			for(int j=1;j<=zs[i];j++){
				if(vis[now][zx[now][j]]==0&&now!=zx[now][j]){
					vis[now][zx[now][j]]=1;
					dfs(zx[now][j],end,time+tdz[now][i]+tdz[i][zx[now][j]]);
				}
			} 
		}
	}
}
void solve(int sta,int end){
//	dfs(sta,end,tdk[sta]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tdk[i];
	}
	for(int i=1;i<=m;i++){
		int ls;
		cin>>ls;
		zs[i]=ls;
		for(int j=1;j<=ls;j++){
			cin>>zx[i][j]>>tdz[i][zx[i][j]];
			xz[zx[i][j]][mq[zx[i][j]]++]=i;
			tdz[i][zx[i][j]]=tdz[i][zx[i][j]];
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		solve(a,b);
	}
	cout<<minn;
	return 0;
	
}
