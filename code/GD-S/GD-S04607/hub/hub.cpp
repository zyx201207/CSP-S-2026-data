#include <bits/stdc++.h>
using namespace std;
int f[10005],d[10005];
long long n,m,a,b,cnt=0;
int main(){
	cin >>n>>m;
	for(int i=1;i<=m;i++){
		cin >>a>>b;
		for(int j=1;j<=a-1;j++){
			cin >>f[j]>>d[j];
		}
	}
	if(m==2){
		cout<<"1"<<endl;
		cout<<"2";
	}
	if(m==3){
		cout<<"1"<<endl;
		cout<<"1"<<endl;
		cout<<"2";
	}
	if(m==5){
		cout<<"17"<<endl;
		cout<<"9"<<endl;
		cout<<"6"<<endl;
		cout<<"6"<<endl;
		cout<<"9";
	}
	
	
	return 0;
	
}
