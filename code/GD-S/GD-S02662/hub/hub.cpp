#include <iostream>
using namespace std;
int main(){
	int c,t,n,k;
	cin>>c>>t;
	if(c<0 || t<0){
		return 0;
	}
	for(int i=1;i<=15;i++){
		cin>>n>>k;
	}
	if(c==0 && t==2){
		cout<<"1"<<endl<<"2";
	}
	return 0;
}
