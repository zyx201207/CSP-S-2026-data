#include<bits/stdc++.h>
using namespace std;
int gm[10022],n,m,d,q,w[1000000],t[1000][1000],a[1000][1000],x,y,c,p;
/*void f(b,v){
	for
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>gm[1]>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>gm[i];
		for(int j=1;j<=gm[i];j++){
		cin>>a[i][j]>>t[i][a[i][j]];
	}
	}
	while(q--){
		cin>>x>>y;
		c=w[x]+w[y];
		if(t[1][x]!=0&&t[1][y]!=0)	c+=t[1][x]+t[1][y];
		if(t[2][x]!=0&&t[2][y]!=0)	c+=t[2][x]+t[2][y];
		if(t[3][x]!=0&&t[3][y]!=0)	c+=t[3][x]+t[3][y];
		if(t[4][x]!=0&&t[4][y]!=0)	c+=t[4][x]+t[4][y];
		if(t[5][x]!=0&&t[5][y]!=0)	c+=t[5][x]+t[5][y];
		if(t[6][x]!=0&&t[6][y]!=0)	c+=t[6][x]+t[6][y];
		//p=10000000;
		//f(n,d);
		cout<<c<<endl;
	}
	return 0;
} 
