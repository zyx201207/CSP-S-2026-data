#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[5];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[1]+a[2]+m==a[3]*2){
			cout<<3;
		}
		else if(a[1]+a[2]+a[3]+m==a[4]*3){
			cout<<4;
		}
		else{
			i++;
		}
	}
	return 0;
}
