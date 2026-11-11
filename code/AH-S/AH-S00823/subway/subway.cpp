#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,q,d,k;
int w[505],a[500505][25],t[500505][25];
int mp[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(mp,0x3f3f3f3f,sizeof mp);
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int l=j;l<=k;l++){
				if(l!=j)mp[a[i][j]][a[i][l]]=mp[a[i][l]][a[i][j]]=t[i][j]+t[i][l];
				else mp[a[i][j]][a[i][l]]=mp[a[i][l]][a[i][j]]=0;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		cout<<w[a]+w[b]+mp[a][b]<<"\n";
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


 0 3 7 20 2
 8 3 6 1 7 2 9 
 3 1 4 2 5 5 100 
 3 2 6 3 1 7 2 
 4 3 2 5 100 4 6 6 7 
 1 6 
 2 3

*/
