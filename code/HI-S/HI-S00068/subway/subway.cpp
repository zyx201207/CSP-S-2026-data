#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int m1[100000],n1[100000][100000],n2[10000][1000],sum=0,r[10000];
	
	for(int i=1;i<=m;i++){
	cin>>m1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>n1[i][0];
		for(int j=1;j<=n1[i][0]*2;j++){
			cin>>n1[i][j];
	}
	
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>n2[i][j];			
		}		
	}
	
	minm=1e18;
	for(int i=1;i<=q;i++){	
	
	for(int i=n2[i][1];i<=n2[i][2]){		
		for(int j=1;j<=n;j++){				
		for(int k=2;k<=n1[i][0]*2;k+=2){
			minm=min(n1[i][k],minm);
	}
	
	}
	sum+=minm;	
	}	
	
	
	
	
	
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
