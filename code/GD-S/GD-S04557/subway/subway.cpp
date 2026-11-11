#include <bits/stdc++.h>
using namespace std;
int w[500010];
int k[500010];
int a[510][50010];
int t[510][50010];
int guo[50010][510];
int ans=-1;
int jy[510][50010];
void dfs(int x,int y,int xn=-1,int ant=0){
	if(ans!=-1&&ant>ans)return;
	if(x==y){
	ans=min(ant,ans);
	if(ans==-1)ans=ant;
	}
	for(int i=1;i<=guo[x][0];i++){
		int cnt=0;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x)cnt=t[i][j];
		}
		for(int j=1;j<k[i];j++){
			if(a[i][j]==x||a[i][j]==xn)continue;
			if(jy[i][j]>t[i][j]+ant+cnt)continue;
			jy[i][j]=ant+cnt+t[i][j];
			dfs(a[i][j],y,x,ant+cnt+t[i][j]);
		}
	}
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			guo[a[i][j]][++guo[a[i][j]][0]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(jy,0,sizeof jy);
		dfs(x,y);
		cout<<ans+w[x]+w[y]<<'\n';
		ans=-1;
	}
} 
