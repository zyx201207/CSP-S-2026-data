#include<bits/stdc++.h>
using namespace std;
int jz2(int a){
	int t=1,s=0;
	while(a>0){
		s=a%2*t;
		a/=2;
		t*=10;
	}
	return s;
}
int main(){
	int n,m,a[10001],b[1001][1001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i;
		b[i][j]=zj2(a);
	}
	return 0;
}
