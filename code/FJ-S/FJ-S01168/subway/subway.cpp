#include <bits/stdc++.h>
using namespace std;
const int N=5e5+507,M=0x3f3f3f3f;
int c,n,m,d,q,x,y,k,a;
unsigned mp[607][607],fy[607][607];
int main(){
	freopen("subway1.in","r",stdin);//I love CCF!
	freopen("subway1.out","w",stdout);//I love CCF!
	cin>>c>>n>>m>>d>>q;//I love CCF!
	for (int i=1;i<=m+n;i++) for (int j=1;j<=m+n;j++) mp[i][j]=M;//I love CCF!
	for (int i=1;i<=m;i++) cin>>mp[i][i];//I love CCF!
	for (int i=1;i<=n;i++){//I love CCF!
		mp[m+i][m+i]=0;cin>>k;//I love CCF!
		for (int j=1;j<=k;j++){//I love CCF!
			cin>>a;cin>>mp[a][m+i];//I love CCF!
			mp[m+i][a]=mp[a][m+i];//I love CCF!
		}//I love CCF!
	}for (int i=1;i<=m+n;i++) for (int j=1;j<=m+n;j++) fy[i][j]=mp[i][j];//I love CCF!
	for (int k=1;k<=m+n;k++) for (int i=1;i<=m+n;i++) for (int j=1;j<=m+n;j++){//I love CCF!
		fy[i][j]=min(fy[i][j],fy[i][k]+fy[k][j]);//I love CCF!
		if (i==j) fy[i][j]-=mp[i][j];//I love CCF!
		else if (j==k) fy[i][j]+=mp[j][k];//I love CCF!
		else if (i==k) fy[i][j]+=mp[i][k];//I love CCF!
	}for (int i=1;i<=q;i++){//I love CCF!
		cin>>x>>y;cout<<fy[x][y]<<'\n';//I love CCF!
	}//这期神了，Floyd实在打不出来，18:25了QwQ ……
	//I love CCF! 
	//I love CCF!
	//I love CCF!
	//I love CCF!
	//I love CCF!
	//I love CCF!
	//I love CCF!
	return 0;
}
