#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[1005];
vector<int>a[1005];
vector<int>b[1005][1005];
int way[1005][1005];
int xl[1005][1005];
int fz(int x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(int)a[i].size();j++){
			if(a[i][j]==x){
				return i;
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			xl[i][x]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			way[j][j+1]=max(xl[i][j]+xl[i][j+1]+w[j]+w[j+1],way[j][j+1]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(xl[j][i]!=0 and xl[k][i]!=0){
					b[j][k].push_back(i);
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(way[i][j]){
				continue;
			}
			for(int i=1;i<=(int)b[fz(i)][fz(j)].size();i++){
				way[i][j]=max( w[i]+w[j]+xl[fz(i)][b[fz(i)][fz(j)][i]]+xl[fz(j)][b[fz(i)][fz(j)][i]]+xl[fz(i)][i]+xl[fz(j)][j] , way[i][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<way[x][y];
		cout<<'\n';
	}
	return 0;
}
