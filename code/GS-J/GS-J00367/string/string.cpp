#include<iostream>
using namespace std;
int main(){
    int n,a[100];
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=2;j++){
    		cin>>a[i*10+j];	    
	}
	}
      for(int i=1;i<=n;i++){
    	for(int j=1;j<=2;j++){
    		cout<<a[i*10+j];   
		}
	}
	return 0;
}
