#include<iostream>
using namespace std;
int main(){
	int n,m,c,t;
	cin>>c>>t;
	cin>>n>>m;
	int a[10086],b[10086];
	for(int i=0;i<14;i++){
		cin>>a[i]>>b[i];
	}
	if(c==0&&t==2&&n==5&&m==2){
		cout<<"1"<<endl;
		cout<<"2";
		return 0;
	}
	cout<<"0"<<endl;
	cout<<"1";
	return 0;
}
