#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,e;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>i;
		e+=i;
	}
	
	
	int p=b/2;
	for(int j=0;j<a;j++){
		if(j<=p){
			c+=1;
			
		}
		
		
	for(int j=0;j<a;j++){
		if(j<=p+1)
			d+=1;
			a=a-(p+1-j);
			
	}	
		cout<<d+1;
	
	return 0;
} 
}
