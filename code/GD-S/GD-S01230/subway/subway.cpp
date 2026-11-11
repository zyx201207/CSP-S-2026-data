#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cm[1005][1005]={1000001},w[1005],t[1005][1005]={1000001},lx[1005][1005],c,d,q,aa,aaa;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
cin>>c>>m>>n>>d>>q;
for(int i=1;i<=n;i++){
	cin>>w[i];
}for(int i=1;i<=m;i++){
	cin>>c;
	for(int j=1;j<=c;j++){
		cin>>lx[i][j]>>t[i][j];
	}
}
for(int k=1;k<=d;k++){
	for(int j=1;lx[k][j]!=0;j++){
	for(int i=1;lx[k][i]!=0;i++){
		cm[i][j]=t[k][i]+t[k][j];
		//cm[j][k]=t[k][1]+t[k][j];
		//cout<<cm[i][j]<<"="<<k<<":"<<t[k][i]<<"+"<<j<<":"<<t[k][j]<<" ";
	}}
}
//cout<<endl;

for(int k=1;k<=n;k++){
	for(int j=k+1;j<=n;j++){
		for(int i=j+1;i<=n;i++){
			//if(cm[k][j]<1e7-7&&cm[k][i]<1e7-7&&cm[i][j]<1e7-7){
				
		cm[k][j]=min(cm[k][j],cm[k][i]+cm[i][j]);
		cm[j][k]=min(cm[j][k],cm[k][i]+cm[i][j]);
		//cout<<k<<"-"<<j<<":"<<cm[k][j]<<" ";
		//}
		
		}
	}//cout<<endl;
}for(int i=0;i<q;i++){
	cin>>aa>>aaa;
	cout<<cm[aa][aaa]<<endl;
}




return 0;
}/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/

