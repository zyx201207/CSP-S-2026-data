#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,d,n,m,q;
	cin>>c>>n>>m>>d>>q;
	int arr[m];
	
	//2
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	
	//i+2
	for(int i=0;i<n;i++){
		int k1[n];
		cin>>k1[i];
		int a1[n][100],t1[n][100];
		for(int j=0;j<k1[i];j++){
			cin>>a1[i][j]>>t1[i][j];
		}
		
	}
	
	//r+n+2
	int x1[q],y1[q];
	for(int i=0;i<q;i++){
		cin>>x1[i]>>y1[i];
	}
	
	
	int a=0,b,f,e;
	for(int i=0;i<q;i++){
		a+=arr[x1[i]]+arr[y1[i]];
		for(int j=0;j<n;j++){
			for(int k=0;k<k1[j];k++){
				if(a1[j][k]==x1[i]){
						
				}
			}
		}
		
	}
	return 0;
}