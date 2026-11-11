#include <bits/stdc++.h>
using namespace std;
int w[500100];
int a[1000][500100];
int r[100100][2];
int main(){
	int c,n,m,d,q;
	cin >>c>>n>>m>>d>>q;
	for(int i=0 ; i<m ; i++){
		cin>>w[i];
	}
	for(int i=0 ; i<n ; i++){
		cin >>a[i][0];
		for(int j=0 ; j<a[i][0] ; j++){
			cin >>a[i][j];
		}
	}
	for(int i=0  ;i<q ; i++){
		cin >>r[i][0]>>r[i][1];
	}
	return 0;
}
