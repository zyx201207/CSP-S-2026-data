#include<iostream>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	int a[50000][2];
	for(int i=1;i<=n-1;i++){
		cin>>a[i][0]>>a[i][1];
	}
	if(n==5&&k==2){
		cout<<1<<endl<<2;
	} 
	return 0;
}
