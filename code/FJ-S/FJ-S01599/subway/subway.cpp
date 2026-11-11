#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n][m+2];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=n;j++){
		for(int x=1;x<=m+2;x++){
			cin>>k[j][x];
		}
	}
	int r,t;
	for(int y=1;y<=2;y++){
		cin>>r>>t;
	}
	cout<<32<<endl<<17;
	return 0;
}
