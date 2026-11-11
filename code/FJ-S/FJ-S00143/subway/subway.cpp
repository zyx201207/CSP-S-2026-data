#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,x,y,c,w[1000000],t[100000][100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[i][j]=y;		
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][y];
	}
	return 0;
}
