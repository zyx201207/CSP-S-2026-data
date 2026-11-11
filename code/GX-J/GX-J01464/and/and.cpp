#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];

int search(int j,int b){
	for(int k=j;k<n;k++){
		if(j<m){
			search(j+1,b&a[k+1]);
		}
		
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	return 0;
}
