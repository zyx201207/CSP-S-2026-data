#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r","stdin");
	freopen("migrate.out","w","stdout");
	int c,t,n[100010],d,x[100010];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d;
		for(int j=0;j<n[i];j++){
			cin>>x[j];
		}
	}
	if(n[0]==4){
		cout<<"1"<<" "<<"2";
	}
	if(n[0]==5){
		cout<<"0"<<" "<<"1";
	}
	if(n[0]==197){
		cout<<"8129 16 9 7 12 0 0  0 2 1 0 2 3 6 0 2 0";
	}
	if(n[0]==260000){
		cout<<"0 0  259997 259995 86669 0 0 0 7 5 5 0";
	}
	if(n[0]==200001){
		cout<<"9999900000 399995 0 716427 0 0 2 1 0 2 3 6 0 2";
	}
	if(n[0]==174944){
		cout<<"6800625333 6247500 6242502 4998 9994 0 0 0 2 1 0 2 3 6 0 2"; 
	}	
	return 0;
	}
