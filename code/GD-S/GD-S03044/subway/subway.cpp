#include<bits/stdc++.h>
using namespace std;
int c,n,m,k[5],d,q,w[20],a[5][20],t[5][20],xx,yy,minn=999;
bool vis[20];
void dfs(int s){
	
	for(int j=1;j<=n;j++){
		for(int h=1;h<=k[j];h++){
			if(xx==a[j][h]&&vis[j]){
				int bc=xx;
				xx=a[j][h];
				s=s+t[j][h];
				vis[j]=false;
				dfs(s);
				s=s-t[j][h];
				xx=bc;
				vis[j]=true;
			}
			if(a[j][h]==yy){
				minn=min(s,minn);
				return;
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
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xx>>yy;
		dfs(w[xx]+w[yy]);
		cout<<minn<<endl;
	}
	return 0;
} 
