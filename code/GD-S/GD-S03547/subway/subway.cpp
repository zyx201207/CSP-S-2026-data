#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,kt[500100],xl[510][500100];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kt[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			xl[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			xl[i][a]=t;
		}
	}
	int x,y,sum=0;
	while(q--){
		cin>>x>>y;
		int r=x,l=1; 
		sum=sum+kt[x]+kt[y]+xl[1][x];
		for(int i=1;i<=n;i++){
			if(r==y) break; 
			if(xl[l][x+i]!=0){
				sum+=xl[l][r+i];
				r+=i;
			}
			else if(xl[l+i][r]!=0){
				sum+=xl[l+i][r];
				l+=i;
			}
		}
		cout<<sum;
	} 
	
	return 0;
} 
