#include<iostream>
using namespace std;
int n,m,k;
int a[1000000];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
    	cin>>a[i];
    	k=max(k,a[i]);
	}
	if(m=1){
		cout<<k;
	}else{
		cout<<0;
	}
	return 0;
}
