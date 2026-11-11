#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int a[500050];
int vis[550][550];
struct node{
	int c,t;
};
node v[500050];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
    	 cin>>a[i];
	}
	for(int i=1,j=1;i<=m;i++,j++){
		vis[i][j]=-1;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v[j].c>>v[j].t;
			for(int it=1;it<j;it++){
				vis[v[j].c][v[it].c]=vis[v[it].c][v[j].c]=v[j].t+v[it].t;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(vis[i][j]==0){
			} 
		}
	}
	for(int i=1;i<=p;i++){
		int x,y;cin>>x>>y;
		cout<<vis[x][y];
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/

