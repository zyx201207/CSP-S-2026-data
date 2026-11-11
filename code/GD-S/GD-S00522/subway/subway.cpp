#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500010],k[510],a[510][50010],t[510][50010],e[110][110],x,y;
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
			e[i][a[i][j]]=1;
			e[a[i][j]][i]=1;
		}		
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(e[x][y]){
			cout<<w[x]+t[x][x]+t[x][y]+w[y]<<'\n';
		}
		else if(e[x][1]){
			cout<<w[x]+t[x][x]+t[x][1]+t[1][1]+t[x][y]+w[y]<<'\n';
		}
		else if(e[x][2]){
			cout<<w[x]+t[x][x]+t[x][2]+t[2][2]+t[x][y]+w[y]<<'\n';
		}
		else if(e[x][3]){
			cout<<w[x]+t[x][x]+t[x][3]+t[3][3]+t[x][y]+w[y]<<'\n';
		}
	}
	return 0;
}
