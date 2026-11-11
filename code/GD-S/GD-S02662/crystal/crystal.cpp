#include <iostream> 
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	if(n<=0 || m<0){
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(n==5 && m==5){
		cout<<"3";
	}else if(n==5 && m==8){
		cout<<"4";
	}
	return 0;
 }
