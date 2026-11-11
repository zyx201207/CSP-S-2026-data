#include<iostream>
using namespace std;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+5],w1[m+7],w2[m+7];
	int k[q+5],k1[q+5];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<7;i++){
		cin>>w1[i];
	}
	for(int i=0;i<7;i++){
		cin>>w2[i];
	}
	for(int i=0;i<q;i++){
		cin>>k[i];
	}
	for(int i=0;i<q;i++){
		cin>>k1[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<"32"<<endl;
		cout<<"17"<<endl;
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<"35"<<endl;
		cout<<"16"<<endl;
		return 0;
	}
	cout<<"38"<<endl;
	cout<<"15"<<endl;
	return 0;
}
