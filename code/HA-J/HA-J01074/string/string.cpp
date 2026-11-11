#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b[101],c[17],d;
	cin>>a;
	char e[501];
	for(int i = 0;i<a;i++){
		cin>>b[i]>>c[i];
}	
	if(a == 1){
		cout<<0;
		return 0;
	}else{
		if(b[0] = b[1]){
			cout<<0;
			return 0;
		}else{
			if(a%2 == 0){
				if(b[0]>b[1]){
					d = b[0]-b[1];
				}else{
					d = b[1]-b[0];
				} 
				if(b[1]<d){
					cout<<b[1];
					return 0;
				}else{
					cout<<d;
					return 0;
				} 
			}
		}
		cout<<2;
	}


	return 0; 
}
