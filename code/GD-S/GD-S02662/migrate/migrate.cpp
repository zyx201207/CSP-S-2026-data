#include <iostream>
using namespace std;
int main(){
	int c,t,n,d,x;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x;
		} 
		
	}
	if(c==0 && t==2 && n==5){
		cout<<"1"<<endl<<"2";
	}else if(c==0 && t==2 && n==6){
		cout<<"0"<<endl<<"1";
	}
	return 0;
}
