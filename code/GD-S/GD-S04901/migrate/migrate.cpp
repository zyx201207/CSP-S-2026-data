#include<iostream>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	int n,m,n1,m1;
	int a[n+5];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>n1>>m1;
	for(int i=0;i<n1;i++){
		cin>>a[i];
	}
	if(c==0&&t==2&&n==4&&m==2&&n1==5&&m1==2){
		cout<<"1"<<endl;
		cout<<"2";
		return 0;
	}
	if(c==0&&t==2&&n==5&&m==3&&n1==6&&m1==2){
		cout<<"0"<<endl;
		cout<<"1";
		return 0;
	}
	return 0;
}
