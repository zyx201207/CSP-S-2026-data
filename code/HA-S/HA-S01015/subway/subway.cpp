#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x,y,xi[500005][25];
int main(){
	freopen( "subway.in","r",stdin );
	freopen( "subway.out","w",stdout );
	cin>>c>>n>>m>>d>>q;
	for( int i=1; i <= m; i++){
		cin>>w[i];
	}
	for( int i=1; i <= n; i++){
		cin>>k[i];
		for( int j=1; j <= k[i]; j++){
			cin>>a[i][j]>>t[i][j];
			xi[a[i][j]][++xi[a[i][j]][0]]=i;
		}
	}
	while( q-- ){
		cin>>x>>y;
		int s=w[x]+w[y];
		int u=1;
		while( x != y ){
			for( int i=1; i <= xi[x][xi[x][0]]; i++){
				for( int j=1; j <= xi[y][xi[y][0]]; j++){
					if( xi[x][i] == xi[y][j] ){
						s+=t[xi[x][i]][x]+t[xi[y][j]][y];
						x=y;
					}
				}
			}
		}
		cout<<s;
	}
	return 0;
}


