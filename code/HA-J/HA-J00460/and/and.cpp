#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	int n,m;
	cin>>n>>m;
	int p[n];
	int map1[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			map1[i][j]=-1;
		}
	}
	int zuida=0;
	for(int i=0;i<n;i++) cin>>p[i],map1[0][i]=p[i];
	sort(p,p+n);
	cout<<p[n-3];
//	for(int i=1;i<m;i++){
//		for(int j=0;j<n;j++){
//			for(int l=0;l<n;l++){
//				if(l==j) continue;
//				map1[i][j]=max(map1[i][j],(map1[i-1][j]&map1[0][l]));
//			}
//			if(i==m-1) zuida=max(zuida,map1[i][j]);
//		}
//	}
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			cout<<map1[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	//cout<<zuida;
	return 0;
}
