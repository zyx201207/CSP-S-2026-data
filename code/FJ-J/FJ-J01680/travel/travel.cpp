#include<bits/stdc++.h>
using namespace std;
string sb1,sb2;
string sz1,sz2;
string sum;
bool f,f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sb1>>sz1>>sb2>>sz2;
	for(int i=0;i<2;i++){
		if(sb1[i]!=sb2[i]){
			f=1;
		}
	}
	if(f==0){
		cout<<1;
	}
	else{
		cout<<0;
	}
	for(int i=0;i<2;i++){
		if(sz1[i]!=sz2[i]){
			f1=1;
		}
	}
	if(f1==1||f==1){
		f1=1;
		cout<<0;
	}
	else{
		cout<<1;
	}
	for(int i=2;i<3;i++){
		if(sz1[i]<='C'&&sz2[i]>'C'){
			f2=1;
		}
		else if(sz1[i]>'C'&&sz1[i]<='C'){
			f2=1;
		}
	}
	if(f2==1||f1==1){
		f2=1;
		cout<<0;
	}
	else cout<<1;
	if((sz1[2]!=sz2[2]+'1')&&(sz1[2]!=sz2[2]-1)){
		f3=1;
	}
	if(f3==1||f2==1){
		cout<<0;
	}
	else cout<<1;
	return 0;
}
