#include<bits/stdc++.h>
using namespace std;
const int N=50100;
int c,n,m,d,q,x,y;
int k[550],a[550][N];
long long w[N],t[550][N];
bool cnct[550][N],vis[550],viss[N];
long long ans;
void dfs(int r,long long o){
	if(r==y){
		ans=min(ans,o);
		return;
	}
	viss[r]=1;
	for(int i=1;i<=n;i++){
		if(cnct[i][r]==1&&vis[i]==0){
			//cout<<i<<"*"<<endl;
			vis[i]=1;
			o+=t[i][r];
			for(int j=1;j<=k[i];j++){
				if(cnct[i][a[i][j]]==1&&viss[a[i][j]]==0){
					viss[a[i][j]]=1;
					o+=t[i][a[i][j]];
					//cout<<i<<" "<<a[i][j]<<" "<<o<<endl;
					dfs(a[i][j],o);
					viss[a[i][j]]=0;
					o-=t[i][a[i][j]];
				}
			}
			vis[i]=0;
			o-=t[i][r];
		}
	}
	viss[r]=0;
	return;
}
int main(){
	//memset(t,0x4f,sizeof(t));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			cnct[i][a[i][j]]=1;
		}
	}
	while(q>0){
		ans=0x3f3f3f3f3f3f;
		cin>>x>>y;
		dfs(x,w[x]+w[y]);
		cout<<ans<<endl;
		q--;
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
