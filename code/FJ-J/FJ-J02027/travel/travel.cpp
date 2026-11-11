#include<bits/stdc++.h>
using namespace std;
ifstream fin ("travel.in");
ofstream fout ("travel.out");
int main(){
	char hang,hang2;
	char lie1;
	char lie2;
	char cx1;
	char cx2;
	cin>>cx1>>lie1>>hang1>>cx2>>lie2>>hang2;
	if(cx1==cx2){
		cout<<"1 ";
	}else{
		cout<<"0 0 0 0";
		return 0;
	}
	if(lie1==lie2){
		cout<<"1 ";
	}else{
		cout<<"0 0 0";
		return 0;
	}
	if(hang1<='C'&&hang2<='C' || hang1>'C'&&hang2>'C'){
		cout<<"1 ";
		if(hang1+1==hang2||hang1-1==hang2){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0 0";
		return 0;
	}
	return 0;
} 
