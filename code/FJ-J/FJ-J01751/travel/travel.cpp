#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int wei1,wei2;
int jin;
int che,pai,ce;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(a==b){
		cout<<"1";
		che=1;
	}
	else if(a!=b){
		cout<<"0";
	}
	if(a1[0]==b1[0]&&a1[1]==b1[1]&&che){
		cout<<"1";
		pai=1;
	}
	else{
		cout<<"0";
	}
	wei1=a1[2]-'A';
	wei1=wei1+1;
	wei2=b1[2]-'A';
	wei2=wei2+1;
	if(wei1<=3&&wei2<=3&&che&&pai){
		cout<<"1";
		ce=1;
	}
	else if(wei1>=4&&wei2>=4){
		cout<<"1";
		ce=1;
	}
	else{
		cout<<"0";
	}
	jin=wei1-wei2;
	if(jin<0){
		jin=-jin;
	}
	if(jin<2&&che&&pai&&ce){
		cout<<"1";
	}
	else{
		cout<<0;
	}
	return 0;
}
