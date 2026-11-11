#include<bits/stdc++.h>
using namespace std;
int a,b;
string a2,b2;
int flog=0,flogg=0,flog2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a2>>b>>b2;
	if(a==b){
		flog2=1;
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1]&&flog2==1){
		cout<<1;
		flog=1;
	}else{
		cout<<0;
	}
	if(((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C'))&&flog==1){
		cout<<1;
		flogg=1;
	}else{
		cout<<0;
	}
	int aa=a2[2]-'A',bb=b2[2]-'A';
	if(flogg==1&&abs(aa-bb)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
