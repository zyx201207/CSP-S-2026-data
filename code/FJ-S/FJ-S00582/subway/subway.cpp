#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,ans,q,ik[22222],ki[22222][555],k[555],w[22222],t[555][22222],a[555][22222],xi,yi;
bool vis[22222];
void dfs(int x,int y,int z){
	if(x==y){
		ans=min(ans,z);
		return ;
	}
	for(int i=0;i<ik[x];i++){
		for(int j=1;j<=k[ki[x][i]/10];j++){
			if(a[ki[x][i]/10][j]!=x&&vis[a[ki[x][i]/10][j]]==0&&z+t[ki[x][i]/10][ki[x][i]%10]+t[ki[x][i]/10][j]<ans){
				vis[a[ki[x][i]/10][j]]=1;
				dfs(a[ki[x][i]/10][j],y,z+t[ki[x][i]/10][ki[x][i]%10]+t[ki[x][i]/10][j]);
				vis[a[ki[x][i]/10][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			ki[a[i][j]][ik[a[i][j]]]=10*i+j;
			ik[a[i][j]]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xi>>yi;
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		ans=1e9;
		dfs(xi,yi,0);
		ans+=w[xi]+w[yi];
		cout<<ans<<endl;
	}
	
	
	return 0;
}
