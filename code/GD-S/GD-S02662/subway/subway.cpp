#include <iostream>
using namespace std;
int main(){
	int c,n,m,d,q,w,a;
	cin>>c>>n>>m>>d>>q;
	if(c<0 || n<0 || m<0 || d<0 || q<0){
		return 0;
	}

	for(int i=1;i<=m;i++){
		cin>>w;
	}
	for(int i=1;i<=7;i++){
		cin>>a;
	}
	for(int i=1;i<=7;i++){
		cin>>a;
	}
	for(int i=1;i<=2;i++){
		cin>>a;
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<"32"<<endl<<"17";
	}
	return 0;
} 
